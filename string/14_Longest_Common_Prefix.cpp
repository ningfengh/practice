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

	string longestCommonPrefix(vector<string>& strs, int start, int end)
	{
		if (start==end) return strs[start];
		int mid = (start+end)/2;
		string str1 = longestCommonPrefix(strs,start,mid);
		string str2 = longestCommonPrefix(strs,mid+1,end);
		string str;
		int i=0,j=0;
		while (i<str1.size() && j<str2.size()&& str1[i]==str2[j])
		{
			str+=str1[i];
			i++;
			j++;
		}
		return str;
	}
    string longestCommonPrefix(vector<string>& strs) {
        int length = strs.size();
		if (length==0) return "";
		return longestCommonPrefix(strs,0,length-1); 
    }
};

int main(void)
{
	Solution mysolution;
	vector <string> input;


	cout<<mysolution.longestCommonPrefix(input);

}