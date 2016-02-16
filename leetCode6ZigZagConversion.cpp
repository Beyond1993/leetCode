#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() == 1 ) return s;
        string res[numRows];
        int i=0, j ,gap = numRows - 2;
        while(i<s.length()){
            for(j = 0 ; i<s.length() && j<numRows ; j++) res[j] += s[i++] ;//res[j].append(s[i++]);i
            for(j = gap; i<s.length() && j>0;j--) res[j] += s[i++];

        }
        string str;
        for(int i =0 ;i<numRows;i++){
            str.append(res[i]);
        }
        return str;
    }
};

int main(){
    cout<<"please input string"<<endl;
    char c[20];
    cin>>c;
    string str(c);

    cout<<"please input n"<<endl;
    int n;
    cin>>n;

    Solution s;
    cout<<s.convert(str,n);
    return 0;
}
