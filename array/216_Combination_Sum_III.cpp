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
	void combinationSum(int k, int target, int pos, vector<vector<int> >& result, int current_sum, vector<int>&current_result, int length)
	{
		int i;
		if (current_sum==target&&length==k)
			result.push_back(current_result);
		if (current_sum>target||length>k)
			return;
		for (i=pos;i<=9;i++)
		{
			current_result.push_back(i);
			current_sum+=i;
			combinationSum(k,target,i+1,result,current_sum,current_result,length+1);
			current_result.pop_back();
			current_sum-=i;			
		}
	}
    vector<vector<int> > combinationSum3(int k, int target) {

		vector<vector<int> > result;
		if (k==0) return result;
		vector<int> current_result;
		combinationSum(k,target,1,result,0,current_result,0);
		return result;
    }
};

int main(void)
{
	Solution mysolution;

	int i;

	vector<vector<int> > output;
	output= mysolution.combinationSum3(3,7);
	for (i=0;i<output.size();i++)
		PrintVector(output[i]);
	
	
}