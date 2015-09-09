#include <iostream>
#include <vector>
#include <algorithm>

/*
very bad,

try many times.
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
    void nextPermutation(vector<int>& nums) {
        size_t length = nums.size();
		int i=length-1;
		while (i>0)
		{
			if (nums[i]>nums[i-1])
				break;
			i--;
		}
		if (i==0)
		{
			for (int j=0;j<length/2;j++)
			{
				int tmp = nums[j];
				nums[j] = nums[length-j-1];
				nums[length-j-1] = tmp;
			}
		}
		else
		{
			int j=length-1;
			while (j>i)
			{
				if (nums[j]<nums[j-1] && nums[j]>nums[i-1])
					break;
				j--;
			}	
			int tmp = nums[j];
			nums[j] = nums[i-1];
			nums[i-1] = tmp;
			sort(nums.begin()+i,nums.end());
		}
    }
};


int main(void)
{

	int a[]={1,3,2};
	Solution mysolution;
	vector<int>  vec_a(a,a+3);
	mysolution.nextPermutation(vec_a);
	PrintVector(vec_a);
}