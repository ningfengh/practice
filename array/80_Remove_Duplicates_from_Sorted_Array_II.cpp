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
        int load = 1,save = 0,flag = 0;
		int length = nums.size();
		if (length==0||length==1) return length;
		
		while(load<length)
		{
			if (nums[load]==nums[load-1])
			{
				load++;
				flag=1;
			}
			else
			{
				
				nums[save]=nums[load-1];
				save++;
				if (flag==1)
				{
					
					nums[save]=nums[load-1];
					save++;
					flag=0;
				}
				load++;
			}
		}
		nums[save]=nums[load-1];
		if (flag==1)
		{
			save++;
			nums[save]=nums[load-1];
			save++;
		}
		else
			save++;
		

		return save;
    }
	
};


int main(void)
{

	int a[]={1,1,1,1,3,3};
	Solution mysolution;
	vector<int>  vec_a(a,a+6);
	cout<<mysolution.removeDuplicates(vec_a)<<endl;
	
	PrintVector(vec_a);

}