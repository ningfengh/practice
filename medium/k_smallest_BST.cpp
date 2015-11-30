class Solution {
public:

	void search (TreeNode* root, vector<int> result,k)
	{
		if (result.size()==k) return;
		if (root==NULL) return;
		search(root->left,result,k);
		result.push_back(root->val);
		search(root->right,result,k);
	}
    int kthSmallest(TreeNode* root, int k) {
		vector <int> result;
		search(root,result,k);
		return result[k-1];
    }
};