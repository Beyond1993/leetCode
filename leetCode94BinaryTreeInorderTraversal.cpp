#include<stdlib.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Definition for a binary tree node.

struct TreeNode {

       int val;

       TreeNode * left;

       TreeNode * right;

       TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};



class Solution {

public:

    vector<int> inorderTraversal(TreeNode *  root) {
		TreeNode * p = root;
		stack<TreeNode*> s;
		vector<int> res;
		while( !s.empty() || p ){
			while( p ){
				s.push(p);
				p = p->left;
			}
			if(!s.empty()){
				p = s.top();
				s.pop();
				res.push_back(p->val);
				p = p->right;
			}
		}

		return res;
    }

};

int main(){
	TreeNode *  root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left  = new TreeNode(3);
	Solution s;
	vector<int> res;
	res = s.inorderTraversal(root);
	for(int i = 0 ; i<res.size();i++){
		cout<<res[i]<<endl;
	}
	return 0;

}
