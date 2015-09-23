#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include <functional>
#include <climits>
using namespace std;
// use a long int, very slow
class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
		long int result = 0;
		int sign = 1;
		while (str[i]==' ') i++;
		if (str[i]=='-') {sign = -1; i++;}
		else if (str[i]=='+') i++;
		for (i;i<str.size();i++)
		{
			cout<<result*sign<<endl;
			if (str[i]>='0' && str[i]<='9') result = result*10+str[i]-'0';
			else 
			{	if (result*sign>INT_MAX) return INT_MAX;
				if (result*sign<INT_MIN) return INT_MIN;
				return result*sign;
			}
			if (result*sign>INT_MAX) return INT_MAX;
			if (result*sign<INT_MIN) return INT_MIN;
		}
		if (result*sign>INT_MAX) return INT_MAX;
		if (result*sign<INT_MIN) return INT_MIN;
		return result*sign;		
    }
};

int main(void)
{
	Solution mysolution;
	cout<<mysolution.myAtoi("9223372036854775809");

}