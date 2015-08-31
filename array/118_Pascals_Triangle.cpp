#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		vector<vector<int> > result;
		vector<int> current_row;
		int i,j;
        if (numRows==0) return result;
		if (numRows==1)
		{
			current_row.resize(1);
			current_row[0] = 1;
			result.push_back(current_row);
			return result;
		}
		if (numRows==2)
		{
			current_row.resize(1);
			current_row[0] = 1;
			result.push_back(current_row);
			current_row.resize(2);
			current_row[0] = 1;
			current_row[1] = 1;
			result.push_back(current_row);
			return result;
		}
		else
		{
			current_row.resize(1);
			current_row[0] = 1;
			result.push_back(current_row);
			current_row.resize(2);
			current_row[0] = 1;
			current_row[1] = 1;
			result.push_back(current_row);
			for (i=2;i<numRows;i++)
			{
				current_row.resize(i+1);
				current_row[0]=1;
				current_row[i]=1;
				for (j=1;j<=i-1;j++)
					current_row[j]=result[i-1][j-1]+result[i-1][j];
				result.push_back(current_row);
			}
		}
    }
};
void PrintVector(vector<int>& in)
{
	int i;
	for (i=0;i<in.size();i++)
		cout<<in[i]<<" ";
	cout<<endl;
}
int main(void)
{
	Solution mysolution;
	int numRows = 5,i;
	vector<vector<int> > result;
	result = mysolution.generate(numRows);
	for (i=0;i<result.size();i++)
		PrintVector(result[i]);
}