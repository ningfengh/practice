#include <iostream>
#include <vector>
#include <algorithm>


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
    int missingNumber(vector<int>& nums) {
        int sum1=0;
		int sum2=0;
		int length=nums.size();
		int i;
		for (i=0;i<length;i++)
		{
			sum1+=i;
			sum2+=nums[i];
		}
		sum1+=i;
		return sum1-sum2;
		
    }
};


int main(void)
{

	int a[]={0,1,3};
	Solution mysolution;
	vector<int>  vec_a(a,a+3);
	cout<<mysolution.missingNumber(vec_a);

}