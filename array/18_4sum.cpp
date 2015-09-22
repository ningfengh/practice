#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

/*
DFS solution 

exceed the time limit

*/
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



class Solution {
public:
	void combinationSum(vector<int>& candidates, int target, int pos, vector<vector<int> >& result, int current_sum, vector<int>&current_result, int length, int k)
	{
		int i,end;
		if (current_sum==target && k==4)
			result.push_back(current_result);
		if (current_sum>target || k>4)
			return;
		for (i=pos;i<length;i+=(end-i))
		{
			end=i;
			while(candidates[++end]==candidates[i]&&end<length);
			//cout<<i<<" "<<end<<endl;
			for (int j=i;j<end;j++)
			{
				current_result.push_back(candidates[j]);
				//PrintVector(current_result);
				current_sum+=candidates[j];
				combinationSum(candidates,target,end,result,current_sum,current_result,length,k+j-i+1);
			}
			for (int j=i;j<end;j++)
			{
				current_result.pop_back();
				current_sum-=candidates[j];
			}				
		}
	}
    vector<vector<int> > fourSum(vector<int>& nums, int target)  {
        int length =  nums.size();
		vector<vector<int> > result;
		if (length==0) return result;
        sort(nums.begin(),nums.end());
		vector<int> current_result;
		combinationSum(nums,target,0,result,0,current_result,length,0);
		return result;        
    }
};

int main(void)
{
	Solution mysolution;
	int in[]={1,0,-1,0,-2,2};
	int i;
	vector<int> input(in,in+6);
	vector<vector<int> > output;
	output= mysolution.fourSum(input,0);
	for (i=0;i<output.size();i++)
		PrintVector(output[i]);
	
	
}