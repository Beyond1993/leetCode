#include<stdlib.h>
#include<iostream>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {

    }
};

int main(){
    TreeNode *  root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left  = new TreeNode(3);

    Solution s ;
    cout<<s.isValidBST(root)<<endl;

}
