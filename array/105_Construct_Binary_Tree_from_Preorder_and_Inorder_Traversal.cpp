#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>


using namespace std;

void PrintVector(vector<int>& in)
{
	int i;
	for (i=0;i<in.size();i++)
		cout<<in[i]<<" ";
	cout<<endl;
}
string to_string(int i)
{
	stringstream ss;
	ss<<i;
	return ss.str();
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, map<int,int>& inorder_map,int length,int start_pre,int start_in)
	{
		TreeNode* leave = new TreeNode(preorder[start_pre]);
		if (length==1) return leave;
		int root_idx = inorder_map[preorder[start_pre]];
		int length_l = root_idx-start_in;
		int length_r = start_in+length-root_idx-1;
		if (length_l!=0)
			leave->left = buildTree(preorder,inorder,inorder_map,length_l,start_pre+1,start_in);
		if (length_r!=0)
			leave->right = buildTree(preorder,inorder,inorder_map,length_r,start_pre+1+length_l,root_idx+1);		
	}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inorder_map;
		int length = preorder.size();
		int i;
		if (length==0) return NULL;
		for (i=0;i<length;i++)
			inorder_map[inorder[i]] = i;
		return buildTree(preorder,inorder,inorder_map,length,0,0); 
		
    }
};

int main(void)
{
	Solution mysolution;
	int pre[]={1,2,4,5,3,6,7};
	int in[] = {4,2,5,1,6,3,7};
	vector<int> pre_order(pre,pre+7);
	vector<int> in_order(in,in+7);
	TreeNode* root;
	root = mysolution.buildTree(pre_order,in_order);
	
	
}