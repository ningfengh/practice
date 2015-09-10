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
    int maxSubArray(vector<int>& nums) {
		int length = nums.size();
		int t,sum,i;
		if (length==0) return 0;
		else 
		{
			sum = nums[0];
			t = nums[0];
		}
		for (i=1;i<length;i++)
		{
			if (t<0) t = nums[i];
			else t+=nums[i];
			if (t>sum) sum=t;
		}
		return sum;
    }
};

int main(void)
{
	Solution mysolution;
	int x[]={-2,1,-3,4,-1,2,1,-5,4};
	vector<int> input(x,x+9);

	cout<<mysolution.maxSubArray(input);
	
}