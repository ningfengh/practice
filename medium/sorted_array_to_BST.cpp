class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums,int begin, int end)
	{
		if (begin>end) return NULL;
		int mid = (begin+end+1)/2;
	    TreeNode* root = new TreeNode(nums[mid]);
		if (begin==end) return root;
		else
		{
			root->left = sortedArrayToBST(nums,begin,mid-1);
			root->right = sortedArrayToBST(nums,mid+1,end);
			return root;
		}
			
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
        int length = nums.size();
		if (length==0) return NULL;
		else return sortedArrayToBST(nums,0,length-1);
    }
};