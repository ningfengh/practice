#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:


	vector<int> diffWaysToCompute(vector <int>& nums; vector<char>& op, int begin, int end)
	{
		vector<int> r;
		vector<int> left;
		vector<int> right;
		int i,j,k;
		if ((end-begin)==0)
		{
			r.push_back(nums[begin]);
			return r;
		}
		else {
			for (i=begin;i<end;i++)
			{
				left = diffWaysToCompute(op,nums,begin,i);
				right = diffWaysToCompute(op,nums,i+1,end);
				if (op[i]=='+')
				{
					for (j=0;j<left.size();j++)
						for (k=0;k<right.size();k++)
							r.push_back(left[j]+right[k]);
				}
				if (op[i]=='-')
				{
					for (j=0;j<left.size();j++)
						for (k=0;k<right.size();k++)
							r.push_back(left[j]-right[k]);
				}
				if (op[i]=='*')
				{
					for (j=0;j<left.size();j++)
						for (k=0;k<right.size();k++)
							r.push_back(left[j]*right[k]);
				}
				if (op[i]=='/')
				{
					for (j=0;j<left.size();j++)
						for (k=0;k<right.size();k++)
							r.push_back(left[j]/right[k]);
				}				
			}
		}
		return r;
			
	}
    vector<int> diffWaysToCompute(string input) {
  
		vector <int> nums;
		vector <char> op;
		string b = "+-*/";
		int i;
		int aa;
		while (1){
			i = strcspn(input.c_str(),b.c_str());
			if (i==input.size()) break;
			aa =stoi (input.substr(0,i),nullptr,10);
			op.push_back(input[i]);
			nums.push_back(aa);
			input = input.substr(i+1,a.size()-i-1);
		}
		aa =stoi (input.substr(0,i),nullptr,10);
		nums.push_back(aa);
		return diffWaysToCompute(nums,op,0,nums.size()-1);
    }
};

int main(void){
	Solution mysolution;
	vector <int> result;
	result = mysolution.diffWaysToCompute("1+2");
}