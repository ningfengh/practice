#include <iostream>
#include <vector>
#include <algorithm>

//O(nlogn)

// understand the problem wrong, subarray cannot switch the order of the numbers
using namespace std;

void PrintVector(vector<int>& in)
{
	int i;
	for (i=0;i<in.size();i++)
		cout<<in[i]<<" ";
	cout<<endl;
}

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        sort(nums.begin(),nums.end(),std::greater<int>());
		PrintVector(nums);
		int sum=0;
		int i;
		int length = nums.size();
		for (i=0;i<length;i++)
		{
			sum+=nums[i];
			if (sum>=s) break;
		}
		if (i==length&&sum<s) return 0;
		else return i+1;
    }
};


int main(void)
{

	int a[]={2,3,1,2,4,3};
	Solution mysolution;
	vector<int>  vec_a(a,a+6);
	cout<<mysolution.minSubArrayLen(7,vec_a);

}