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
/* string process + stack */

using namespace std;



class Solution {
public:
    int calculate(string s) {
        stack <int> nums;
		stack <char> op;
		int current_nums = -1;
		for (int i=0;i<s.size();i++)
		{
			
			if (s[i]==' ' && current_nums == -1) continue;
			if (s[i]==' '){
				nums.push(current_nums);
				current_nums = -1;
				continue;
			}
			if (s[i]=='*' || s[i]=='/'){
				nums.push(current_nums);
				op.push(s[i]);
				current_nums = -1;
				continue;
			}
			if (s[i]=='+' || s[i]=='-'){
				if (!op.empty() && (op.top()=='*'||op.top()=='/'))
				{
					int tmp = nums.top();
					nums.pop();
					if (op.top()=='*') nums.push(tmp*current_nums);
					else nums.push(tmp/current_nums);
					op.pop();
					current_nums = -1;
					continue;
				}
				else
				{
					nums.push(current_nums);
					current_nums = -1;
					op.push(s[i]);
					continue;
				}
			}
			if (current_nums==-1)
				current_nums = s[i]-'0';
			else
				current_nums = current_nums*10+s[i]-'0';
			
		}
		if (current_nums!=-1) nums.push(current_nums);
		while (op.size()!=0)
		{
			char op_tmp = op.top();
			op.pop();
			int num2 = nums.top();
			nums.pop();
			int num1 = nums.top();
			nums.pop();
			if (op_tmp=='+') nums.push(num1+num2);
			else if (op_tmp=='-')nums.push(num1-num2);
			else if (op_tmp=='*')nums.push(num1*num2);
			else if (op_tmp=='/')nums.push(num1/num2);
		}
		return nums.top();
		
    }
};

int main(void)
{
	Solution mysolution;

	cout<<mysolution.calculate("100000000/2/1");
	
}