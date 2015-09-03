#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
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

	void add(vector<int>& nums, vector<vector<int> >& result, vector<int>& current, int length, int current_pt, int size)
	{
		int i;
		if (size==0)
		{
			result.push_back(current);
			return;
		}
		else
		{
			for (i=current_pt;i<=length-size;i++)
			{
				current.push_back(nums[i]);
				add(nums,result,current,length,i+1,size-1);
				current.pop_back();
			}
		}
		
	}
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
		vector<int> current;
		int length = nums.size();
		int i;
		sort(nums.begin(),nums.end());
		for (i=0;i<=length;i++)
		{
			add(nums,result,current,length,0,i);
		}
		
		
		
		return result;
	}
};

int main(void)
{
	Solution mysolution;
	int x[]={4,1,0};
	int i;
	vector<int> input(x,x+3);
	vector<vector<int> > result;
	result = mysolution.subsets(input);
	cout<<"result="<<endl;
	for (i=0;i<result.size();i++)
		PrintVector(result[i]);
}