#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include <functional>
#include <climits>
#include <sstream>
/* time exceed  */

using namespace std;

void PrintVector(vector<string>& in)
{
	int i;
	for (i=0;i<in.size();i++)
		cout<<in[i]<<" ";
	cout<<endl;
}



class Solution {
public:
    string longestPalindrome(string s) {
        string rev_s="";
		int length = s.size();
		int i,j;
		for (i = length-1;i>=0;i--)
			rev_s+=s[i];
		i = 0 ; j = 0;
		string current = "";
		string longest = "";
		for (i=0;i<length;i++)
		{
			for (j=0;j<length;j++)
			{
				if (length-i<longest.size()||length-j<longest.size()) break;
				string current = "";
				int itmp=i,jtmp=j;
				while (s[itmp]==rev_s[jtmp]&&itmp<length){current+=s[itmp];itmp++;jtmp++;}
				if (current.size()>longest.size()) longest = current;
			}
		}
		return longest;
    }
};

int main(void)
{
	Solution mysolution;
	
	cout<< mysolution.longestPalindrome("abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa");


}