#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        char str[12];
        bool p = true;
        sprintf(str,"%d",x);
    cout<<str<<endl;
      cout<<strlen(str)<<endl;
        int length = strlen(str);
        int n = 0;
        if(0 == length % 2) n = length / 2;
        else n =(length -1) / 2;
        for(int i=0;i<n;i++){
            if(str[i] != str[ length - 1 - i])
                p = false;

        }
        return p;
    }
};

int main(){
    int a = 0;
    cin>>a;
    Solution s ;
    bool b = s.isPalindrome(a);
    cout<<b<<endl;
    return 0;
}
