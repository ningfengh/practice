#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1);
		vector<int> tmp(rowIndex+1);
		int i,j;
		
		rowIndex++;
		result[0]=1;
		for (i=1;i<rowIndex;i++)
		{
			tmp = result;
			result[0]=1;
			for (j=1;j<i;j++)
				result[j] = tmp[j-1]+tmp[j];
			result[i] = 1;
		}
		return result;
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
	int rowIndex = 0,i;
	vector<int>  result;
	result = mysolution.getRow(rowIndex);
	PrintVector(result);
}