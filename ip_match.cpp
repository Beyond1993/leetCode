#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define N 255

void DecToBin(unsigned int dec,string &b)
{

      int i = 7;
      while(i >= 0)
      {
         int temp  = dec;
         temp = temp >> i;
         b[8-i-1] = (temp & 1)+'0';
         i--;
      }
}

string ipToBinary(string ip){
    int count = 0,sum = 0;
    int len = ip.length();
    string binary = "";
    string b(8,'0');
   //cout<<b<<endl;
    for (int i = 0; i <= len; i++)
    {
        if (ip[i] != '.' && i != len)
            sum = sum*10 + ip[i] - '0';
        else
        {
            count++;
            DecToBin(sum,b);
            //cout<<b;
            binary += b;
           // if (count !=4)
                //binary += ".";
            //cout<<".";
            //cout<<b<<endl;
            sum = 0;
        }
    }
    return binary;
}
string flag(string str){
    if(str == "allow")
        return "YES";
    if(str == "deny")
        return "NO";

    return NULL;
}
int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    vector<string> ips;
    vector<string> masks;
    string str1;
    string str2;
    vector<string> ipsFlag;
    vector<string> masksFlag;
    for(int i=0;i<n;i++){
        cin>>str1;
        cin>>str2;
        int len2  = str2.length();
        if(str2[len2 - 2] =='/') {
            int t1 = str2[len2 -1] - '0';

            string s = ipToBinary(str2);
            s = s.substr(0,t1);
            //cout<<s<<endl;
            masksFlag.push_back(flag(str1));
            masks.push_back(s);
        }
        if(str2[len2 -3] == '/'){
            int t2 = (str2[len2 - 2]-'0') * 10 + str2[len2 -1] - '0';
            string s = ipToBinary(str2);
            s = s.substr(0,t2);
            masksFlag.push_back(flag(str1));
            masks.push_back(s);
            //cout<<s<<endl;
        }else{
       // cout<<str2<<endl;
            ipsFlag.push_back(flag(str1));
            ips.push_back(ipToBinary(str2));

        }
    }
    string str3;
    for(int j=0;j<m;j++ ){
        cin>>str3;
        int a =0;
        str3 = ipToBinary(str3);
        for(int h=0;h<ips.size();h++){
              if( str3 == ips[h]){
                cout<<ipsFlag[h]<<endl;
                a = 1;
                break;
              }
        }
        if(a == 0){
        for(int k=0;k<masks.size();k++){
            string tmp = str3.substr(0, masks[k].length());
            if(tmp == masks[k]){
                cout<<masksFlag[k]<<endl;
                break;
            }
        }

        }
    }
    //string str;
    //while(cin>>str){
      //  cout<<ipToBinary(str)<<endl;
//}
return 0;
}
