#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:

    void add(vector<string> &v ,string str, int left , int right){
        if(left==0 && right == 0){
            cout<<endl<<"result "<<str<<endl<<endl;
            v.push_back(str);
            return ;
        }

        if(left > 0){
            //cout<<"left is "<<left<<" "<<str<<endl;

            add(v,str+"(", left-1, right);
        }

        if(right>0&&left<right){
           // cout<<"right is :"<<right<<" "<<str<<endl;

            add(v,str+")", left, right-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n==0)
            return res;

        add(res,"",n,n);
        return res;

    }
};

int main(){
    Solution s;

    s.generateParenthesis(2);
    return 0;
}
