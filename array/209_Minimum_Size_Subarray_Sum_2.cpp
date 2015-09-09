#include <iostream>
#include <vector>
#include <algorithm>

// saw tag of two pointers
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
		int length = nums.size();
		int start = 0, end = 0;
		int sum = 0;
		int min = 0;
		while (end<length)
		{
			sum+=nums[end];
			end++;
			while (sum>=s)
			{
				if (min==0 || end-start<min)
				{
					min = end-start;
				}
				
				sum-=nums[start];
				start++;
				
			}
			//cout<<start<<" "<<end<<" "<<sum<<endl;
		}			
		return min;
    }
};


int main(void)
{

	int a[]={2,3,1,2,4,3};
	Solution mysolution;
	vector<int>  vec_a(a,a+6);
	cout<<mysolution.minSubArrayLen(7,vec_a);

}