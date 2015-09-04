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
	int searchInsert(vector<int>& nums, int target,int head, int tail)
	{
		int center;
	
		if (head==tail) 
			if (target>nums[head]) return head+1;
			else return head;
		else
		{
			center = (tail+head+1)/2;
			if (nums[center]==target) return center;
			else if (nums[center]>target)
			{
				return searchInsert(nums,target,head,center-1);
			}
			else if (nums[center]<target)
			{
				return searchInsert(nums,target,center,tail);
			}
				
		}
			
	}
    int searchInsert(vector<int>& nums, int target) {

        return searchInsert(nums,target,0,nums.size()-1);
		
    }
};


int main(void)
{

	int a[]={3,4,6,8,10};
	Solution mysolution;
	vector<int>  vec_a(a,a+5);
	cout<<mysolution.searchInsert(vec_a, 11)<<endl;

}