/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *left, TreeLinkNode *right)
	{
		if (left==NULL || right==NULL) return;
		left->next = right;
		connect(left->left,left->right);
		connect(right->left,right->right);
		connect(left->right,right->left);
		return;
	}
    void connect(TreeLinkNode *root) {
		if (root==NULL) return;
        connect(root->left,root->right);
		return;
    }
};