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
		int start = 0, end = length-1;
		
    }
};


int main(void)
{

	int a[]={2,3,1,2,4,3};
	Solution mysolution;
	vector<int>  vec_a(a,a+6);
	cout<<mysolution.minSubArrayLen(7,vec_a);

}