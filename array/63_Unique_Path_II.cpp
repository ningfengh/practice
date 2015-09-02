#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        vector<vector<int> >result(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
		int i,j;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if(obstacleGrid[0][0]==0) result[0][0]=1;
		for (i=1;i<m;i++)
			if(obstacleGrid[i][0]==0) result[i][0]=result[i-1][0]; 
		for (i=1;i<n;i++)
			if (obstacleGrid[0][i]==0)result[0][i]=result[0][i-1];
		for (i=1;i<m;i++)
			for (j=1;j<n;j++)
				if (obstacleGrid[i][j]==0)
				result[i][j]=result[i-1][j]+result[i][j-1];
		return result[m-1][n-1];
    }
};

int main(void)
{
	Solution mysolution;
	vector<vector<int> > obstacleGrid(3,vector<int>(3,0));
	obstacleGrid[0][0] = 1;
	cout<<mysolution.uniquePathsWithObstacles(obstacleGrid);

}