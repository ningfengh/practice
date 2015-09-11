#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

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
		if (end-begin==1)
			if (nums[end]>nums[begin]) return end;
		    else return begin;
		int mid = (end+begin+1)/2;
		
		if (nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]) return mid;
		else if (nums[mid]<nums[mid-1]) return findPeakElement(nums,begin,mid,length);
		else return findPeakElement(nums,mid,end,length);
			
	}
    int findPeakElement(vector<int>& nums) {
        int length = nums.size();
		if (length==1) return 0;
		return findPeakElement(nums,0,length-1,length);
    }
};

int main(void)
{
	Solution mysolution;
	int x[]={1,2,3,4};
	vector<int> input(x,x+4);

	cout<<mysolution.findPeakElement(input);
	
	
}