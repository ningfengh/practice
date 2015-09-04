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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
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
	
	cout<<mysolution.searchMatrix(matrix,3);
	

}