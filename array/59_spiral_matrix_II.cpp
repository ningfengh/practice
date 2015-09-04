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
    vector<vector<int> > generateMatrix(int n) {
        if (n==0) 
		{
			vector<vector<int> >matrix;
			return matrix;
		}
		vector<vector<int> >matrix(n,vector<int>(n,0));
		int num = 1;
		int i=0,j=0;
		matrix[i][j]=num;
		int length = n*n-1;
		int top_wall=1,bottom_wall=n-1,left_wall=0,right_wall=n-1;
		while (length!=0)
		{
		while (length!=0 && j<right_wall)
		{
			j++;
			length--;
			matrix[i][j] = ++num;			
		}
		while (length!=0 && i<bottom_wall)
		{
			i++;
			length--;
			matrix[i][j] = ++num;			
		}
		while (length!=0 && j>left_wall)
		{
			j--;
			length--;
			matrix[i][j] = ++num;			
		}
		while (length!=0 && i>top_wall)
		{
			i--;
			length--;
			matrix[i][j] = ++num;			
		}
		right_wall--;
		left_wall++;
		top_wall++;
		bottom_wall--;
		}
		return matrix;
    }
};

int main(void)
{
	Solution mysolution;
	int i;
	vector<vector<int> > matrix;
	matrix = mysolution.generateMatrix(3);

	for (i=0;i<matrix.size();i++)
	{
		PrintVector(matrix[i]);
	}


}