#include <iostream>
#include <vector>
#include <algorithm>

/*
using a sort, efficiency is pretty bad


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
    int majorityElement(vector<int>& nums) {
        int length = nums.size();
		int count = 1,i;
		sort (nums.begin(), nums.end()); 
		if (length==1) return nums[0];
		for (i=1;i<length;i++)
		{
		
			if (nums[i]==nums[i-1]) count++;
			else count = 1;
			if (count>(int)(length/2))
				return nums[i];
		}
    }
};


int main(void)
{
	int rowIndex = 0,i;
	int a[]={2,2,1,1,1,2,2};
	int m,n;
	Solution mysolution;
	vector<int>  vec_a(a,a+7);
	cout<<mysolution.majorityElement(vec_a)<<endl;

}