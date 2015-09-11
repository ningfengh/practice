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
    int maxProduct(vector<int>& nums) {
        int length = nums.size();
		int large=nums[0],small=nums[0];
		int max = nums[0];
		int i;
		for (i=1;i<length;i++)
		{
			vector<int> tmp(3,0);
			tmp[0] = nums[i];
			tmp[1] = nums[i]*large;
			tmp[2] = nums[i]*small;
			sort(tmp.begin(),tmp.end());
			large = tmp[2];
			small = tmp[0];
			if (large>max) max=large;
		}
		
		return max;
    }
	
};

int main(void)
{
	Solution mysolution;
	int x[]={-2,1,-3,4,-1,2,1,-5,4};
	vector<int> input(x,x+9);

	cout<<mysolution.maxProduct(input);
	
}