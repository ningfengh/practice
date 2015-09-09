#include <iostream>
#include <vector>
#include <algorithm>

/*
cannot figure out by myself
check the answer in the discussion
O(1) space and O(n) time
*/


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
    vector<int> productExceptSelf(vector<int>& nums) {
		size_t length = nums.size();
		vector <int> result(length,1);
		int i;
		int tmp;
		// scan from right
		for (i=length-2;i>=0;i--)
		{
			result[i]=result[i+1]*nums[i+1];
		}
		tmp=1;
		for (i=0;i<length;i++)
		{
			result[i] = result[i]*tmp;
			tmp = tmp*nums[i];
		}
		return result;
    }
};


int main(void)
{

	int a[]={1};
	Solution mysolution;
	vector<int>  vec_a;
	vector<int>  vec_b;
	vec_b = mysolution.productExceptSelf(vec_a);
	PrintVector(vec_b);
}