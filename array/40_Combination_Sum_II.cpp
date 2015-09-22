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
	void combinationSum(vector<int>& candidates, int target, int pos, vector<vector<int> >& result, int current_sum, vector<int>&current_result, int length)
	{
		int i,end;
		if (current_sum==target)
			result.push_back(current_result);
		if (current_sum>target)
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
				combinationSum(candidates,target,end,result,current_sum,current_result,length);
			}
			for (int j=i;j<end;j++)
			{
				current_result.pop_back();
				current_sum-=candidates[j];
			}				
		}
	}
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
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
	int in[]={10,1,2,7,6,1,5,8};
	int i;
	vector<int> input(in,in+8);
	vector<vector<int> > output;
	output= mysolution.combinationSum2(input,8);
	for (i=0;i<output.size();i++)
		PrintVector(output[i]);
	
	
}