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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    }
};


int main(void)
{
	int rowIndex = 0,i;
	int a[]={1,2,3,4,5};
	int b[]={6,7,8,9,10};
	int m,n;
	vector<int>  vec_a(a,a+5);
	vector<int>  vec_b(b,b+5);
	m = vec_a.size();
	n = vec_b.size();
	vec_a.resize(m+n);
	PrintVector(vec_a);
	PrintVector(vec_b);
}