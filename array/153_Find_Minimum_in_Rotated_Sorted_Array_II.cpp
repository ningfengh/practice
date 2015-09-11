#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
/* trying to modify 162 to this problem,
however, 162 only always search half space,
for this problem, the binary search need to search both side, basically, using 
the binary search to find the min value , like divide and conquer 
the worse case complexity should be O(n) rather than O(logn) */
using namespace std;

void PrintVector(vector<int>& in)
{
	int i;
	for (i=0;i<in.size();i++)
		cout<<in[i]<<" ";
	cout<<endl;
}
string to_string(int i)
{
	stringstream ss;
	ss<<i;
	return ss.str();
}

class Solution {
public:
	int min(int a,int b)
	{
		if (a>b) return b;
		else return a;
	}
	int findMin(vector<int>& nums,int begin,int end, int& length) {
		//cout<<begin<<" "<<end<<endl;
		if (end-begin==1)
			if (nums[end]>nums[begin]) return nums[begin];
		    else return nums[end];
		int mid = (end+begin)/2;
		
		if (nums[mid]<nums[mid-1]&&nums[mid]<nums[mid+1]) return nums[mid];
		else return min(findMin(nums,mid,end,length),findMin(nums,begin,mid,length));
			
	}
    int findMin(vector<int>& nums) {
        int length = nums.size();
		if (length==1) return nums[0];
		return findMin(nums,0,length-1,length);

    }
};

int main(void)
{
	Solution mysolution;
	int x[]={5,6,0,1,2,3,4};
	vector<int> input(x,x+6);

	cout<<mysolution.findMin(input);
	
	
}