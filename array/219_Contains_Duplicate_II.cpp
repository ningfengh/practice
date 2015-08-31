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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map <int,int> mymap;
		int length = nums.size();
		int i;
		for (i=0;i<length;i++)
		{
			if (mymap.count(nums[i])!=0)
			{
				if (i-mymap[nums[i]]<=k)
					return true;
				else
					mymap[nums[i]]=i;
			}
			else
				mymap[nums[i]]=i;
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