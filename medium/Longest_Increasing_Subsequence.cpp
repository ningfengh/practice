class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> longest(nums.size(),0);
		int max_global = 1;
		longest[0] = 1;
		for (int i=1;i<nums.size();i++){
			int max=1;
			for (int j=0;j<i-1;j++)
			{
				if (nums[j]<nums[i])
					if (longest[j]+1>max) max = longest[j]+1;
			}
			longest[i] = max;
			if (max>max_global) max_global = max;
		}
		return max_global;
    }
};