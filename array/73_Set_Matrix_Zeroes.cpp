#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
string to_string(int i)
{
	stringstream ss;
	ss<<i;
	return ss.str();
}

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        int m=matrix.size(); // num of rows
		if (m==0) return;
		int n=matrix[0].size();
		if (m*n<=1) return;
		int i,j,k;
		for (i=1;i<m;i++)
		{
			for (j=1;j<n;j++)
				if (matrix[i][j]==0)
				{					
					matrix[0][j]=0;
					matrix[i][0]=0;
				}

				
		}
		for (i=m-1;i>=0;i--)
		{
			for (j=n-1;j>=0;j--)
				if (matrix[0][j]==0||matrix[i][0]==0)
				{					
					matrix[i][j]=0;
				}
				
		}
    }
};

int main(void)
{
	Solution mysolution;
	int x[5][4]={{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
	int i;
	vector<vector<int> > matrix;
	for (i=0;i<5;i++)
	{
		vector <int> tmp(x[i],x[i]+4);
		matrix.push_back(tmp);
	}
	mysolution.setZeroes(matrix);
	
	for (i=0;i<matrix.size();i++)
	{
		PrintVector(matrix[i]);
	}

}