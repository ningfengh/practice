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



class Solution {
public:
	void combinationSum(vector<int>& candidates,int target, int pos, vector<vector<int> >& result, int current_sum, vector<int>&current_result, int length)
	{
		int i;
		if (current_sum==target)
			result.push_back(current_result);
		if (current_sum>target)
			return;
		for (i=pos;i<length;i++)
		{
			current_result.push_back(candidates[i]);
			current_sum+=candidates[i];
			combinationSum(candidates,target,i,result,current_sum,current_result,length);
			current_result.pop_back();
			current_sum-=candidates[i];			
		}
	}
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        int length = candidates.size();
		vector<vector<int> > result;
		if (length==0) return result;
        sort(candidates.begin(),candidates.end());
		vector<int> current_result;
		combinationSum(candidates,target,0,result,0,current_result,length);
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	int in[]={2,3,6,7};
	int i;
	vector<int> input(in,in+4);
	vector<vector<int> > output;
	output= mysolution.combinationSum(input,7);
	for (i=0;i<output.size();i++)
		PrintVector(output[i]);
	
	
}