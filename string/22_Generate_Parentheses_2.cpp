#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <set>
#include <functional>
#include <climits>
#include <sstream>
#include <map>
#include <stack>

using namespace std;


class Solution {
public:
    void generateParenthesis(int n,int left,int right,string& current, vector<string> &result)
	{
		int i;
		if (left==n && right==n) 
		{
			result.push_back(current);
			return;
		}
		else
		{
					
			if (left<n)
			{
				current = current+'(';
				generateParenthesis(n,left+1,right,current,result);
				current = current.substr(0,current.size()-1);
			}
			if (left>right && left<=n) {
				current = current+')';
				generateParenthesis(n,left,right+1,current,result);
				current = current.substr(0,current.size()-1);
			}
			
		}
	}
	
	vector<string> generateParenthesis(int n) {
        vector<string> result;
		if (n==0) return result;
		string current="(";
		generateParenthesis(n,1,0,current,result);
    }
};

int main(void)
{
	Solution mysolution;
	vector <string> result;
	result = mysolution.generateParenthesis(3);
	for (int i = 0;i<result.size();i++)
		cout<<result[i]<<" ";
	
}