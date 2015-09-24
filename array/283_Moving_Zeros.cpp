#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

/*
two pointers
*/
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
    void moveZeroes(vector<int>& nums) {
        int nz = 0;
		int z = 0;
		int length=nums.size();
		int temp;
		while (nz<length-1 && z<length-1)
		{
			while (nums[z]!=0 && z<length-1) z++;
			nz = z+1;
			if (nz>length-1) break;
			while (nums[nz]==0 && nz<length-1) nz++;
			temp = nums[nz];nums[nz]=nums[z];nums[z]=temp;
		}
    }
};

int main(void)
{
	Solution mysolution;
	
	int in[]={4,2,4,0,0,3,0,5,1,0};
	int i;
	vector<int> input(in,in+10);
	mysolution.moveZeroes(input);
	PrintVector(input);

	
	
}