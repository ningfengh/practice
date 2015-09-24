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
    int strStr(string haystack, string needle) {
        int length1 = haystack.size();
		int length2 = needle.size();
		int i =0,j=0;
		while (i<length1 && j<length2)
		{
			//cout<<i<<" "<<j<<endl;
			if (haystack[i]!=needle[j]) 
			{
				i=i-j+1;
				j = 0;
			}
			else
			{
				i++;
				j++;
			}
		}
		if (j==length2)
			return i-length2;
		else
			return -1;
    }
};

int main(void)
{
	Solution mysolution;
	


	cout<<mysolution.strStr("mississippi","issip");

}