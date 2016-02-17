#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool search(vector<vector<char> > &board, string &word, vector<vector<bool> > &isValid, int k, int i, int j) {
        if (k == word.length() - 1 && word[k] == board[i][j]){
                return true;
        }
        //cout<<board[i][j];
        isValid[i][j] = false;

        if (j + 1 < board[0].size() && isValid[i][j+1] && board[i][j+1] == word[k+1]) {
            if (search(board, word, isValid, k+1, i, j + 1))
                return true;
        }
        if (i + 1 < board.size() && isValid[i+1][j] && board[i+1][j] == word[k+1]) {
           if (search(board, word, isValid, k+1, i + 1, j))
                return true;
        }
        if (i - 1 >= 0 && isValid[i-1][j] && board[i-1][j] == word[k+1]) {
           if (search(board, word, isValid, k+1, i - 1, j))
                return true;
        }
        if (j - 1 >= 0 && isValid[i][j-1] && board[i][j-1] == word[k+1]) {
           if (search(board, word, isValid, k+1, i, j - 1))
                return true;
        }
        isValid[i][j] = true;
        return false;
    }

    bool exist(vector<vector<char> > &board, string word) {
        vector<vector<bool> > isValid(board.size(), vector<bool>(board[0].size(), true));
        if (board.size() < 1) return false;
        for (int i = 0; i <board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0] ) {
                    if(search(board, word, isValid, 0, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};

//["ABCE","SFCS","ADEE"]  ABCESFCSADEE
//"ABCCED"

int main(){
   char c[3][4] = {'A','B','C','E','S','F','C','S','A','D','E','E'};
    //char c[3][4] = {"ABCE","SFCS","ADEE"};
    vector<char> boardCol(4);
    vector<vector<char> > b(3,boardCol);
    for(int i=0;i<b.size();i++){
        for(int j=0 ; j<b[i].size() ; j++){
            b[i][j] = c[i][j];
        }
    }
    Solution s;
    cout<<s.eiist(b,"ABCCED");
    return 0;
}


