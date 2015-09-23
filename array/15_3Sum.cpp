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
		for (k=0;k<length-2&&nums[k]<=0;k++)
		{
			//cout<<k<<" "<<i<<" "<<j<<endl;
			i= k+1;
			j = length-1;
			while (i<j)
			{
				//cout<<k<<" "<<i<<" "<<j<<endl;
				if (nums[i]+nums[j]+nums[k]==0)
				{
					vector<int> tmp;
					tmp.push_back(nums[k]);
					tmp.push_back(nums[i]);
					tmp.push_back(nums[j]);
					result.push_back(tmp);
					cout<<"check  "<<k<<" "<<i<<" "<<j<<endl;

					while (nums[i+1]==nums[i]&&i<j) i++;
					while (nums[j-1]==nums[j]&&i<j) j--;
					i++;
					j--;
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
				
			}
			
			while (nums[k+1]==nums[k]&&k<length-2&&nums[k]<=0) k++;
			
		}
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	//int in[]={7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	int in[]={-1,0,1};
	int i;
	vector<int> input(in,in+3);
	vector<vector<int> > output;
	output= mysolution.threeSum(input);
	for (i=0;i<output.size();i++)
		PrintVector(output[i]);
	
	
}