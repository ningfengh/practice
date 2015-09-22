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

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, map<int,int>& inorder_map,int length,int start_post,int start_in)
	{
		TreeNode* leave = new TreeNode(postorder[start_post+length-1]);
		if (length==1) return leave;
		int root_idx = inorder_map[postorder[start_post+length-1]];

		int length_l = root_idx-start_in;
		int length_r = start_in+length-root_idx-1;
		if (length_l!=0)
			leave->left = buildTree(inorder,postorder,inorder_map,length_l,start_post,start_in);
		if (length_r!=0)
			leave->right = buildTree(inorder,postorder,inorder_map,length_r,start_post+length_l,root_idx+1);		
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inorder_map;
		int length = postorder.size();
		int i;
		if (length==0) return NULL;
		for (i=0;i<length;i++)
			inorder_map[inorder[i]] = i;
		return buildTree(inorder,postorder,inorder_map,length,0,0); 
		
    }
};

int main(void)
{
	Solution mysolution;
	int post[]={4,5,2,6,7,3,1};
	int in[] = {4,2,5,1,6,3,7};
	vector<int> post_order(post,post+7);
	vector<int> in_order(in,in+7);
	TreeNode* root;
	root = mysolution.buildTree(in_order,post_order);
	
	
}