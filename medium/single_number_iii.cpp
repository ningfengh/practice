class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> myset;
        for (int i=0;i<nums.size();i++)
		{
			if (myset.find(nums[i])!=myset.end()) myset.erase(nums[i]);
			else myset.insert(nums[i]);			
		}
		vector<int> result;
		result.assign(myset.begin(),myset.end());
		return result;
    }
};