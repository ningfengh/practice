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

    vector<vector<int> > twoSum(vector<int>& nums, int target)  {
		sort(nums.begin(),nums.end());
		int i=0,j=nums.size()-1;
		vector<vector<int> > result;
		while (i<j)
		{
			if (nums[i]+nums[j]==target)
			{
				cout<<nums[i]<<" "<<nums[j]<<endl;
				while (nums[i+1]==nums[i]&&i<j) i++;
				while (nums[j-1]==nums[j]&&i<j) j--;
			}
			else if (nums[i]+nums[j]>target)
				j--;
			else i++;
			
		}
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	int in[]={2,2,2,2,2,2};
	int i;
	vector<int> input(in,in+6);
	vector<vector<int> > output;
	output= mysolution.twoSum(input,4);
	//for (i=0;i<output.size();i++)
		//PrintVector(output[i]);
	
	
}