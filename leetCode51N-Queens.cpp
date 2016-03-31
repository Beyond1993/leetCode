#include<string>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    bool isValid(int k ,int * X){

        for(int i=0;i<k;i++)
             if((X[k] == X[i] )|| abs(X[k] - X[i]) == abs(i - k) )
                return false;

        return true;
    }
    vector< vector<string> > solveNQueens(int n) {
        vector< vector<string> > res ;
        int solutionIndex = 0;
        int * X = new int[n];
        X[0] = -1;
        int k = 0;
        while(k>-1){//这个wile的判断条件！！ 如果是k<n的话，会出现死循环,然而，当退到 k =0 , X[0] = 3,时 ,最开始的X[k] = X[k] + 1; 会使得X[0] = 4; k = k -1 = -1 退出循环
                X[k] = X[k] + 1;
            while(X[k]<n && !isValid(k,X)) //这里会有一个死循环，因为对于4皇后，X[1] =2时，它是不冲突的，所以直接跳过while循环,又到下一个，又退回，
                X[k] = X[k] + 1;

             if(X[k] >= n)
                k = k - 1;
             else{
                 if(k == n-1) {

                     vector<string> tempRes ;
                     for(int i=0;i<n;i++){
                         cout<<X[i];
                        string tmpStr(n,'.');
                        tmpStr.replace(X[i],1,"Q");
                        tempRes.push_back(tmpStr);
                     }


                     res.push_back(tempRes);

                 }
                 else{
                     k++ ;
                     X[k] = -1;
                 }
             }

        }

        return res;

    }
};

int main(){
    Solution s;
    vector< vector<string> > res;
    res = s.solveNQueens(4);
    for(int i=0;i < res.size();i++){
        cout<<endl;
        for(int j=0;j<res[i].size();j++)
        cout<<res[i][j]<<endl;
    }
    return 0;
}
