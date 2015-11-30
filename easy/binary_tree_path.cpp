class Solution {
public:
	string int2str(int a)
	{
		stringstream ss;
		ss<<a;
		string str=ss.str();
		return string;
	}
	void binaryTreePaths(TreeNode* root,vector<string>& result, string& current)
	{
		if (root->left==NULL && root->right==NULL)
		{
			
			current+=int2str(root->val);
			result.push_back(current);
			return;
		}
		else
		{
			current+=int2str(root->val);
			current+="->";
			if (root->left!=NULL) binaryTreePaths(root->left,result,current);
			if (root->right!=NULL) binaryTreePaths(root->right,result,current);
		}
		
	}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
		string current;
		if (root==NULL) return result;
		binaryTreePaths(root,result,current);
		return result;			
		

    }
};