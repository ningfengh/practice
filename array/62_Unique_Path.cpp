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
    int uniquePaths(int m, int n) {
        vector <vector<int> > result(m,vector<int>(n,0));
		int i,j;
		for (i=0;i<m;i++)
			result[i][0]=1;
		for (i=1;i<n;i++)
			result[0][i]=1;
		for (i=1;i<m;i++)
			for (j=1;j<n;j++)
				result[i][j]=result[i-1][j]+result[i][j-1];
		return result[m-1][n-1];
    }
};


int main(void)
{
	Solution mysolution;
	cout<<mysolution.uniquePaths(3,3);

}