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
    int min(int a,int b)
	{
		if (a>b) return b;
		else return a;
	}
	int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size(); // rows;
		if (m==0) return 0; //columns;
		int n = grid[0].size();
		int i,j;
		for (i=1;i<m;i++) grid[i][0]+= grid[i-1][0];
		for (j=1;j<n;j++) grid[0][j]+= grid[0][j-1];
		for (i=1;i<m;i++)
			for (j=1;j<n;j++)
				grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
		return grid[m-1][n-1];
    }
};

int main(void)
{
	Solution mysolution;
	int x[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int i;
	vector<vector<int> > matrix;

	for (i=0;i<3;i++)
	{
		vector <int> tmp(x[i],x[i]+3);
		matrix.push_back(tmp);
	}
	
	cout<<mysolution.minPathSum(matrix);
}

