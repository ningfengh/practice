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

	int find_row(vector<vector<int> >&matrix, int target, int head, int tail)
	{
		//cout<<head<<" "<<tail<<endl;
		if (head==tail) 
			if (matrix[head][0]<=target) return head;
			else return -1;
		int center = (tail+head+1)/2;
		if (matrix[center][0]==target) return center;
		else if (matrix[center][0]<target)
			return find_row(matrix,target,center,tail);
		else if (matrix[center][0]>target)
			return find_row(matrix,target,head,center-1);
		else return -1;
	}
	
	int find_col(vector<int> &array, int target, int head, int tail)
	{
		//cout<<head<<" "<<tail<<endl;
		if (head==tail) 
			if (array[head]!=target) return -1;
			else return head;
		int center = (tail+head+1)/2;
		if (array[center]==target) return center;
		else if (array[center]<target)
			return find_col(array,target,center,tail);
		else if (array[center]>target)
			return find_col(array,target,head,center-1);
		else return -1;
	}
	
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.size()==0) return false;
		int m = matrix.size();
		int n = matrix[0].size();
		int row = find_row(matrix,target,0,m-1);
		int col;
		//cout<<row<<endl;
		if (row!=-1) 
			col = find_col(matrix[row],target,0,n-1);
		else return false;
		if (col!=-1) return true; else return false;
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
	
	cout<<mysolution.searchMatrix(matrix,1);
	

}