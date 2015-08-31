#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
    bool containsDuplicate(vector<int>& nums) {
        int i,length;
		set <int> myset;
		length = nums.size();
		for (i =0; i<length;i++)
		{
			if (myset.count(nums[i])!=0) return true;
			else myset.insert(nums[i]);
		}
		return false;
    }
};


int main(void)
{
	int rowIndex = 0,i;
	int a[]={2,2,1,1,1,2,2};
	int m,n;
	Solution mysolution;
	vector<int>  vec_a(a,a+7);
	

}