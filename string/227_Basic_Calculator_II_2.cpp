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
/* need from left to right */
using namespace std;



class Solution {
public:
    int calculate(string s) {
        stack <int> nums;
		stack <char> op;
		int current_nums = -1;
		int factor = 1;
		for (int i=s.size()-1;i>=0;i--)
		{
			
			if (s[i]==' ' && current_nums == -1) continue;
			if (s[i]==' '){
				nums.push(current_nums);
				current_nums = -1;
				continue;
			}
			if (s[i]=='*' || s[i]=='/'){
				if (current_nums!=-1) nums.push(current_nums);
				op.push(s[i]);
				current_nums = -1;
				factor = 1;
				continue;
			}			
			if (s[i]=='+' || s[i]=='-'){
				if (current_nums!=-1) nums.push(current_nums);
				while (!op.empty() && (op.top()=='*'||op.top()=='/'))
				{
					int num1 = nums.top();
					nums.pop();
					int num2 = nums.top();
					nums.pop();
					if (op.top()=='*') nums.push(num1*num2);
					else nums.push(num1/num2);
					cout<<" num top "<<nums.top()<<endl;
					op.pop();
				}
				
				current_nums = -1;
				factor = 1;
				op.push(s[i]);	
				
				continue;
			}
			if (current_nums==-1)
			
				current_nums = s[i]-'0';
				
			else
			{
				factor*=10;
				current_nums = current_nums+ (s[i]-'0')*factor;
			}
			cout<<current_nums<<" "<<nums.size()<<" ";
			if (!nums.empty()) cout<<nums.top()<<endl;
			else cout<<endl;
			
			
		}
		cout<<op.top()<<" "<<current_nums<<endl<<nums.top()<<endl;
		if (current_nums!=-1) nums.push(current_nums);
		while (op.size()!=0)
		{
			char op_tmp = op.top();
			op.pop();
			int num2 = nums.top();
			nums.pop();
			int num1 = nums.top();
			nums.pop();
			if (op_tmp=='+') nums.push(num2+num1);
			else if (op_tmp=='-')nums.push(num2-num1);
			else if (op_tmp=='*')nums.push(num2*num1);
			else if (op_tmp=='/')nums.push(num2/num1);
			//cout<<nums.top()<<endl;
		}
		if (nums.empty()) return current_nums;
		else return nums.top();
		
    }
};

int main(void)
{
	Solution mysolution;

	cout<<mysolution.calculate("1+2*5/3");
	
}