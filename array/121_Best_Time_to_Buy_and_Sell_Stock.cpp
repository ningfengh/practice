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
		int max_profit;
		if (prices[1]>prices[0]) max_profit = prices[1]-prices[0];
		else max_profit = 0;
		int current_profit = max_profit;
		for (i=2;i<length;i++)
		{
			
			if (prices[i]-prices[i-1]+current_profit>0)
				current_profit += prices[i]-prices[i-1];
			else
				current_profit = 0;
			cout<<i<<" "<<current_profit<<endl;
			if (current_profit>max_profit)
				max_profit = current_profit;
		}
		return max_profit;
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