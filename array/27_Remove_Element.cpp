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
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
		if (length==0) return 0;
		int tail = length-1;
		int head = 0;
		while (head<=tail)
		{
			if (nums[head]==val) 
			{
				nums[head] = nums[tail];
				tail--;
				length--;
			}
			else
				head++;
		}
		return length;
    }
};

int main(void)
{

	int a[]={1};
	Solution mysolution;
	vector<int>  vec_a(a,a+1);
	cout<<mysolution.removeElement(vec_a, 1)<<endl;
	
	PrintVector(vec_a);

}