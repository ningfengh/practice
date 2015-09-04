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
	int searchFirst(vector<int>& nums, int target,int head, int tail)
	{
		int center;
	 
		if (head==tail) 
			if (nums[head]==target) return head;
			else return -1;
		else
		{
			center = (tail+head+1)/2;
						
			if (nums[center]==target && (center==0 || nums[center-1]!=target)) return center;
			else if (nums[center]>=target)
			{
				return searchFirst(nums,target,head,center-1);
			}
			else if (nums[center]<target)
			{
				return searchFirst(nums,target,center,tail);
			}
				
		}
			
	}
	int searchLast(vector<int>& nums, int target,int head, int tail)
	{
		int center;
			 
		if (head==tail) 
			if (nums[head]==target) return head;
			else return -1;
		else
		{
			center = (tail+head+1)/2;
						
			if (nums[center]==target && (center==nums.size()-1 || nums[center+1]!=target)) return center;
			else if (nums[center]>target)
			{
				return searchLast(nums,target,head,center-1);
			}
			else if (nums[center]<=target)
			{
				return searchLast(nums,target,center,tail);
			}
				
		}
			
	}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
		int length = nums.size();
	
		result[0] = searchFirst(nums,target,0,length-1);
		
		result[1] = searchLast(nums,target,0,length-1);	
	
		
		return result;
		
    }

};


int main(void)
{

	int a[]={2,2};
	Solution mysolution;
	vector<int>  vec_a(a,a+2);
	vector<int> result;
	result = mysolution.searchRange(vec_a, 3);
	cout<<result[0]<<" "<<result[1]<<endl;

}