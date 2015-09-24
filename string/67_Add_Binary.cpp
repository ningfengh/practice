#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include <functional>
#include <climits>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int length1 = a.size();
		int length2 = b.size();
		int sum,carry=0;
		string result="";
		if (length1==0) return b;
		else if (length2==0) return a;
		int i = 1;
		while (length2-i>=0 && length1-i>=0)
		{
			sum = (a[length1-i]-'0')+(b[length2-i]-'0')+carry;
			if (sum>1) 
			{
				sum-=2;
				carry=1;
			}
			else carry = 0;
			if (sum==0) result = '0'+result;
			else result = '1'+result;
			i++;
		}

		while (length1-i>=0)
		{
			sum = (a[length1-i]-'0')+carry;
			if (sum>1) 
			{
				sum-=2;
				carry=1;
			}
			else carry = 0;
			if (sum==0) result = '0'+result;
			else result = '1'+result;
			i++;
		}


		while (length2-i>=0)
		{
			sum = (b[length2-i]-'0')+carry;
			if (sum>1) 
			{
				sum-=2;
				carry=1;
			}
			else carry = 0;
			if (sum==0) result = '0'+result;
			else result = '1'+result;
			i++;
		}
		if (carry==1) result = '1'+result;
				
		return result;
		
    }
};

int main(void)
{
	Solution mysolution;
	


	cout<<mysolution.addBinary("11","1");

}