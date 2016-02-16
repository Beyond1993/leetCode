#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

//for input  "" "+" "+-2" 均输出0   "  -110"  输出-110 "  -0012a24" 要输出-12   "2147483648" 输出2147483647
class Solution {
public:
    int myAtoi(string str) {

 if(str.empty()){
            return 0;
        }

        if(str == "+" || str == "-")
            return 0;
        str.erase(0,str.find_first_not_of(" "));
        str.erase(0,str.find_first_not_of(" "));
        int countOperation = 0;
        int countNum = 0;
        for(int  i=0;i<str.length();i++){
            if(str[i] =='+'|| str[i] == '-') countOperation ++;

            if(str[i] >='0' && str[i] <= '9') countNum ++;
        }
        if(countOperation >1 || countNum == 0 ) return 0;

        int nnn = str.length();
        for(int i=0;i<str.length();i++){
            if((str[i] >'9' || str[i]<'0') && str[i] != '+' && str[i] != '-'){
                str.erase(i);
                break;
            }
        }
        if(str[0] == '+') {
            str = str.substr(1,str.length()-1);

        }


        long long result = 0;//define long long first
        int n = str.length();
        int times  = n ;
        if(str[0]=='-') {
            times = n - 1;
            if(times>11) return -pow(2,31);
        }

        if(times>11) return pow(2,31) -1;

        for(int i=0;i<times;i++){
            //cout<<str[i]<<endl;
            result = result + ( str[n-1 -i] - 48 )* pow(10,i);
        }
        if(str[0] == '-') result = 0 - result;

        if(result > (pow(2,31) -1) ) result = pow(2,31) -1;

        if( result < -pow(2,31)) result = -pow(2,31);

        return (int)result;
    }
};

int main(){
    Solution s;
    while(true){
        string str = " b11228552307";
        string str2 = "9223372036854775809";
       // cin>>str;
       // const char * str2 = str.c_str();
        //int pcResult = atoi(str2);
        //cout<<pcResult<<endl;
        int result = s.myAtoi(str2);
        cout<<result<<endl;
        break;
    }
    return 0;
}
