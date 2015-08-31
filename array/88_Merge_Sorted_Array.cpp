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
        int i,j;
		i = 0;
		j = 0;
		if (m==0) 
		{
			nums1=nums2;
			return;
		}
		while (i<m&&j<n)
		{
			if (nums2[j]<nums1[i])
			{
				nums1.insert(nums1.begin()+i,nums2[j]);
				j++;
				m++;
			}
			i++;
		}
		while (j<n)
		{
			nums1.insert(nums1.begin()+i,nums2[j]);
			j++;
			i++;
			m++;
		}
		nums1.resize(m);
		return;
			
    }
};


int main(void)
{
	int rowIndex = 0,i;
	int a[]={1,2,3,4,5};
	int b[]={6,7,8,9,10};
	int m,n;
	Solution mysolution;
	vector<int>  vec_a(a,a+5);
	vector<int>  vec_b(b,b+5);
	m = vec_a.size();
	n = vec_b.size();
	vec_a.resize(m+n);
	PrintVector(vec_a);
	PrintVector(vec_b);
	mysolution.merge(vec_a,m,vec_b,n);
	PrintVector(vec_a);
}