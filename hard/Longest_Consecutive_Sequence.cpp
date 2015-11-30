#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> myset(nums.begin(),nums.end());
		int longest=0, current=0;
		for (int i:myset)
		{
			current = 1;
			myset.erase(i);
			int ii = i;
			while (myset.find(ii-1)!=myset.end())
			{
				current++;
				ii--;
				myset.erase(ii);
				
			}
			ii = i;
			while (myset.find(ii+1)!=myset.end())
			{
				current++;
				ii++;
				myset.erase(ii);
				
			}			
			if (current>longest) longest = current;
		}
		return  longest;
    }
};

int main(void)
{
	Solution mysolution;
	int a[] = {-1,1,0};
	vector<int> nums(a,a+3);
	cout<<mysolution.longestConsecutive(nums)<<endl;
}