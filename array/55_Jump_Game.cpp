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
	int max(int a, int b)
	{
		if (a<b) return b;
		else return a;
	}
    bool canJump(vector<int>& nums) {
        int i;
		int length = nums.size();
		for (i=1;i<length;i++)
		{
			if (nums[i-1]==0) return false;
			nums[i] = max(nums[i-1]-1,nums[i]);
			//PrintVector(nums);
		}
		//cout<<i<<endl;
		return true;
    }
};

int main(void)
{
	Solution mysolution;
	int x[]={2,0,0};
	vector<int> input(x,x+3);

	cout<<mysolution.canJump(input);
	
	
}