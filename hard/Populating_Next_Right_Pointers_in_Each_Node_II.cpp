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
    void populate_hier(TreeLinkNode *root,int depth,vector<vector<TreeLinkNode*> >& hier)
	{
		if (hier.size()==depth)
		{
			vector<TreeLinkNode*> tmp;
			tmp.push_back(root);
			hier.push_back(tmp);
		}
		else
			hier[depth].push_back(root);
		if (root->left!=NULL)
			populate_hier(root->left,depth+1,hier);
		if (root->right!=NULL)
			populate_hier(root->right,depth+1,hier);
	}
	void connect(TreeLinkNode *root) {
			if (root==NULL) return;
			vector<vector<TreeLinkNode*> > hier;
			populate_hier(root,0,hier);
			for (int i = 0; i < hier.size(); i++)
			{
				for (int j = 0; j < hier[i].size-1; j++)
					hier[i][j]->next = hier[i][j+1];
			}
			return;
    }
};