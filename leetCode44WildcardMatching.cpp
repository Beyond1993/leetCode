#include<iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p=="") return s=="";
        if(p[0]!='*'){
          return isMatch(s.substr(1),p.substr(1));
        } else { // meet *
            int pHead = 1;
            int i = pHead; //pHead
            int sHead = 0;
            int j = sHead; //sHead

            do{
                if(p[i]==s[j]){
                    i++;
                    j++;
                    //if(i==)
                }else{
                    i=pHead;
                    sHead = sHead+1;
                    j=sHead;
                }
            }while(i<p.length()&&j<s.length()&&p[i]!='*');

            if(i==p.length() && j==s.length()) return true;
            if(p[i] == '*') return isMatch(s.substr(++j),p.substr(i));
            else return false;

        }

    }
};

int main(){
    Solution s;
    return 0;
}
