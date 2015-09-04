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
		set <int> zero_i;
		set <int> zero_j;
		
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
				if (matrix[i][j]==0)
				{					
					zero_i.insert(i);
					zero_j.insert(j);
				}
		for (set<int>::iterator it=zero_i.begin(); it!=zero_i.end(); ++it)
			for (j=0;j<n;j++)
				matrix[*it][j] = 0;
		
		for (set<int>::iterator it=zero_j.begin(); it!=zero_j.end(); ++it)
			for (i=0;i<m;i++)
				matrix[i][*it] = 0;			
		
		
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