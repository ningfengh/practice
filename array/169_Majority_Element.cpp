#include <iostream>
#include <vector>
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
    int majorityElement(vector<int>& nums) {
        
    }
};


int main(void)
{
	int rowIndex = 0,i;
	int a[]={1,1,1,1,1,2,3,4,5,6};
	int m,n;
	Solution mysolution;
	vector<int>  vec_a(a,a+10);
	cout<<mysolution.majorityElement(vec_a)<<endl;

}