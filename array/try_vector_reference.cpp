#include <iostream>
#include <vector>
using namespace std;

void try_reference(vector<int> &in)
{
	in[0]=999;
}

void PrintVector(vector<int>& in)
{
	int i;
	for (i=0;i<in.size();i++)
		cout<<in[i]<<" ";
	cout<<endl;
}
int main(void)
{
	int rowIndex = 0,i;
	int a[]={1,2,3,4,5};
	vector<int>  result(a,a+5);
	PrintVector(result);
	try_reference(result);
	PrintVector(result);
}