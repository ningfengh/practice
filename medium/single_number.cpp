class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum1=0,sum2=0;
		set <int> myset;
		for (int i=0;i<nums.size();i++)
		{
			sum2 += nums[i];
			if (myset.find(nums[i])==myset.end())
			{
				sum1+=nums[i];
				myset.insert(nums[i]);
			}
		}
		return sum1*2-sum2;
    }
};