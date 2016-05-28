#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once.
        //int row[9],col[9];
        map<char,int> row;
        map<char,int> col;

        for(int i = 0; i < 9; i++)
        {
            for(int k=1;k<=9;k++){
                row[k+'0'] = 0;
                col[k+'0'] = 0;
            }
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    if(row[board[i][j]] > 0)return false;
                    else row[board[i][j]]++;
                }
                if(board[j][i] != '.')
                {
                    if(col[board[j][i]] > 0)return false;
                    else col[board[j][i]]++;
                }
            }
        }

        for(int i = 0; i < 9; i+=3)
            for(int j = 0; j < 9; j+=3)
            {
                for(int k=1;k<=9;k++){
                    row[k+'0'] = 0;

                }
                for(int p = 0; p < 3; p++)
                    for(int q= 0; q < 3; q++)
                        if(board[i+p][j+q] != '.')
                        {
                            if(row[board[i+p][j+q]]>0)return false;
                            else row[board[i+p][j+q]]++;
                        }
            }
        return true;
    }
};
int main(){
    cout<<"hello world"<<endl;
    string str[] = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
    //string str[] = {"..4...63.",".........","5......9.","...56....","4.3.....1","...7.....","...5.....",".........","........."};
    // for(int i=0;i<9;i++){
     //   cout<<str[i]<<endl;
    //}
    vector<vector<char> > input;
    vector<char> tmp;

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            tmp.push_back(str[i][j]);
        }

        input.push_back(tmp);
        tmp.clear();
    }

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<input[i][j];
        }
        cout<<endl;
    }

    Solution s;
    if(s.isValidSudoku(input))cout<<"true"<<endl;
    else cout<<"false"<<endl;

    return 0;
}
