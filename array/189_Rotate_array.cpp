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
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp=nums;
		int length =nums.size(),i;
		for (i=0;i<length;i++)
			nums[i]=tmp[((i-k)%length+length)%length];
    }
};


int main(void)
{

	int a[]={1,2,3,4,5,6,7};
	Solution mysolution;
	vector<int>  vec_a(a,a+7);
	mysolution.rotate(vec_a, 3);
	PrintVector(vec_a);

}