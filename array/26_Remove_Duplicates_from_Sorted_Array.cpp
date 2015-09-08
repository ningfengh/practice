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
    int removeDuplicates(vector<int>& nums) {
        int load = 1,save = 0;
		int length = nums.size();
		if (length==0||length==1) return length;
		
		while(load<length)
		{
			if (nums[load]==nums[load-1])
				load++;
			else
			{
				save++;
				nums[save]=nums[load];
				load++;
			}
		}

		return ++save;
    }
	
};

int main(void)
{

	int a[]={0,0,0,0,0};
	Solution mysolution;
	vector<int>  vec_a(a,a+5);
	cout<<mysolution.removeDuplicates(vec_a)<<endl;
	
	PrintVector(vec_a);

}