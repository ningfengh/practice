/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void inorderTraversal(TreeNode*root, vector<int> & result)
	{
		if (root==NULL) return;
		
		inorderTraversal(root->left,result);
		result.push_back(root->val);
		inorderTraversal(root->right,result);
	}


    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
		inorderTraversal(root,result);
		return result;
    }
};