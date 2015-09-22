#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>


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
    int maxProfit(vector<int>& prices) {
		int length = prices.size();
		int i;
		if (length<=1) return 0;
		int buy = 0;
		int sell = 0;
		int profit = 0;
		for (i=1;i<length;i++)
		{
			if (prices[i]<prices[i-1]) 
			{
				profit+= prices[i-1]-prices[buy];
				buy = i;
				
			}
			//cout<<i<<" "<<buy<<endl;
		}
		if (prices[i-1]>prices[buy]) profit+= prices[i-1]-prices[buy];
		return profit;
    }
};

int main(void)
{
	Solution mysolution;
	int in[]={6,1,3,2,4,7};
	int i;
	vector<int> input(in,in+6);
	cout<<mysolution.maxProfit(input)<<endl;
	
	
}