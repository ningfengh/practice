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
    vector<int> majorityElement(vector<int>& nums) {
        pair <int,int> v1,v2;
		int length = nums.size();
		int i;
		vector <int> result;
		v1.first = 0;v1.second = 0;
		v2.first = 0;v2.second = 0;
		
		for (i=0;i<length;i++)
		{
			if (v1.second==0||nums[i]==v1.first) {v1.first = nums[i]; v1.second++;}
			else if (v2.second==0||nums[i]==v2.first) {v2.first = nums[i]; v2.second++;}
			else {v1.second--;	v2.second--;}
		}
		
		v1.second = 0;
		v2.second = 0;
		for (i=0;i<length;i++)
		{
			if (nums[i]==v1.first) v1.second++;
			if (nums[i]==v2.first) v2.second++;
		}
		
		if (v1.second>length/3) result.push_back(v1.first); 
		if (v2.second>length/3&&v2.first!=v1.first) result.push_back(v2.first);
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	int x[]={1,1,1,2,2,2,3,3};
	vector<int> input(x,x+8);
	vector<int> result;
	result = mysolution.majorityElement(input);
	PrintVector(result);
	
}