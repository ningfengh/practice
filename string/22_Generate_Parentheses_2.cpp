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
			for (i=left+1;i<=n;i++)
			{
				current = current+'(';
				generateParenthesis(n,i,right,current,result);
			}
			current = current.substr(0,current.size()-(n-left));
			
			for (i=right+1;i<=left;i++)
			{
				current = current+')';
				generateParenthesis(n,left,i,current,result);
			}
			if (left-right>0) current = current.substr(0,current.size()-(left-right));			
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