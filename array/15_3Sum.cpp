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

    vector<vector<int> > threeSum(vector<int>& nums)  {
		vector<vector<int> > result;
		int length = nums.size();
		if (length<3) return result;
		sort(nums.begin(),nums.end());
		
		int k = 0, i=1,j=length-1;
		for (k=0;k<length&&nums[k]<=0;k++)
		{
			//cout<<k<<" "<<i<<" "<<j<<endl;
			i= k+1;
			while (i<j)
			{
				if (nums[i]+nums[j]+nums[k]==0)
				{
					vector<int> tmp;
					tmp.push_back(nums[k]);
					tmp.push_back(nums[i]);
					tmp.push_back(nums[j]);
					result.push_back(tmp);
					i++;
					j--;
					while (nums[i+1]==nums[i]&&i<j) i++;
					while (nums[j-1]==nums[j]&&i<j) j--;
				}
				else if (nums[i]+nums[j]+nums[k]>0)
				{
					while (nums[j-1]==nums[j]&&i<j) j--;
					j--;
				}
				else 
				{
					while (nums[i+1]==nums[i]&&i<j) i++;
					i++;
				}	
				
				//cout<<k<<" "<<i<<" "<<j<<endl;
			}
			while (nums[k+1]==nums[k]&&k<length-1&&nums[k]<=0) k++;
		}
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	int in[]={-1,0,1,2,-1,-4};
	int i;
	vector<int> input(in,in+6);
	vector<vector<int> > output;
	output= mysolution.threeSum(input);
	for (i=0;i<output.size();i++)
		PrintVector(output[i]);
	
	
}