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
	int findPeakElement(vector<int>& nums,int begin,int end, int& length) {
		cout<<begin<<" "<<end<<endl;
		if (end-begin==1)
			if (nums[0]>nums[length-1]) return 0;
		    else return length-1;
		int mid = (end+begin+1)/2;
		
		if (nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]) return mid;
		else if (nums[mid]<nums[mid-1]) return findPeakElement(nums,begin,mid,length);
		else return findPeakElement(nums,mid,end,length);
			
	}
    int findMin(vector<int>& nums) {
        int length = nums.size();
		if (length==1) return nums[0];
		int i=findPeakElement(nums,0,length-1,length);
		if (i==length-1) return nums[0];
		else return nums[i+1];
    }
};

int main(void)
{
	Solution mysolution;
	int x[]={5,6,1,2,3,4};
	vector<int> input(x,x+6);

	cout<<mysolution.findMin(input);
	
	
}