class Solution {
public:

	void permute(vector<int>& nums, vector<vector<int> >& result,int current_length,vector<int>& current_result,vector<int>& occupy,int length)
	{
		if (current_length == length) 
		{
			result.push_back(current_result);
			return;
		}
		for (int i=0;i<length;i++)
		{
			if (occupy[i]!=0) 
			{
				current_result.push_back(nums[i]);
				occupy[i]=1;
				permute(nums,result,current_length+1,current_result,occupy,length);
				occupy[i]=0;
				current_result.pop_back();
			}
		}
	}
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
		int length = nums.size();
		vector<int> occupy (length,0);
		vector<int> current_result;
		permute(nums,result,0,current_result,occupy,length);
		return result;
    }
};class Solution {
public:

	void permute(vector<int>& nums, vector<vector<int> >& result,int current_length,vector<int>& current_result,vector<int>& occupy,int length)
	{
		if (current_length == length) 
		{
			result.push_back(current_result);
			return;
		}
		for (int i=0;i<length;i++)
		{
			if (occupy[i]!=0) 
			{
				current_result.push_back(nums[i]);
				occupy[i]=1;
				permute(nums,result,current_length+1,current_result,occupy,length);
				occupy[i]=0;
				current_result.pop_back();
			}
		}
	}
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
		int length = nums.size();
		vector<int> occupy (length,0);
		vector<int> current_result;
		permute(nums,result,0,current_result,occupy,length);
		return result;
    }
};