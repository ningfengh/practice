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
	int min(int a,int b)
	{
		if (a<b) return a;
		else return b;
	}
    int minimumTotal(vector<vector<int> >& triangle) {
        int n=triangle.size(),m;
		int i,j;
		if (n==1) return triangle[0][0];
		for (i=1;i<n;i++)
		{
			
			m = triangle[i].size();
			triangle[i][0]+=triangle[i-1][0];
			triangle[i][m-1]+=triangle[i-1][m-2];
			for (j=1;j<m-1;j++)
				triangle[i][j]=triangle[i][j]+min(triangle[i-1][j-1],triangle[i-1][j]);
			PrintVector(triangle[i]);
			
		}
		sort(triangle[n-1].begin(),triangle[n-1].end());
		return triangle[n-1][0];
    }
};

int main(void)
{
	Solution mysolution;
	vector<vector<int> > triangle;
	int l1[]={2};
	vector<int> l1_v(l1,l1+1);
	int l2[]={3,4};
	vector<int> l2_v(l2,l2+2);
	int l3[]={6,5,7};
	vector<int> l3_v(l3,l3+3);
	int l4[]={4,1,8,3};
	vector<int> l4_v(l4,l4+4);
	triangle.push_back(l1_v);

	triangle.push_back(l2_v);	
	triangle.push_back(l3_v);	
	triangle.push_back(l4_v);		
	

	cout<<mysolution.minimumTotal(triangle);

}