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
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
		int m = matrix.size(); // num of rows
		if (m==0) return result;
		int n = matrix[0].size(); // num of columns;
		int length = m*n-1;
		if (m*n==0) return result;
		int i=0,j=0;
		result.push_back(matrix[i][j]);
		int top_wall=1,bottom_wall=m-1,left_wall=0,right_wall=n-1;
		while (length!=0)
		{
		while (length!=0 && j<right_wall)
		{
			j++;
			length--;
			result.push_back(matrix[i][j]);			
		}
		while (length!=0 && i<bottom_wall)
		{
			i++;
			length--;
			result.push_back(matrix[i][j]);			
		}
		while (length!=0 && j>left_wall)
		{
			j--;
			length--;
			result.push_back(matrix[i][j]);			
		}
		while (length!=0 && i>top_wall)
		{
			i--;
			length--;
			result.push_back(matrix[i][j]);			
		}
		right_wall--;
		left_wall++;
		top_wall++;
		bottom_wall--;
		}
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	int x[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int i;
	vector<vector<int> > matrix;
	vector<vector<int> > matrix1;
	vector<int> result;
	for (i=0;i<3;i++)
	{
		vector <int> tmp(x[i],x[i]+3);
		matrix.push_back(tmp);
	}
	result = mysolution.spiralOrder(matrix1);
	PrintVector(result);
	

}