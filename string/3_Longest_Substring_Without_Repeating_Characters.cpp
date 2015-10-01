#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <set>
#include <functional>
#include <climits>
#include <sstream>
/* DP  */

using namespace std;
void PrintSet(set<char>& in)
{
	set<char>::iterator i;
	for (i=in.begin();i!=in.end();i++)
		cout<<*i<<" ";
	cout<<endl;
}
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set <char> charset;
		int current_length = 0;
		int pt1=0,pt2=0;
		int length = s.size();
		int max = 0;
		while (pt2<length)
		{
			if (charset.find(s[pt2])!=charset.end()) 
			{
				while (s[pt1]!=s[pt2]) {charset.erase(s[pt1]);pt1++;current_length--;}
				pt1++;
				pt2++;	
				cout<<pt1<<" "<<pt2<<endl;
				PrintSet(charset);				
			}
			
			while (pt2<length && charset.find(s[pt2])==charset.end()) 
			{
				charset.insert(s[pt2]);
				pt2++;
				current_length++;
				if (current_length>max) max = current_length;
				cout<<pt1<<" "<<pt2<<endl;
				PrintSet(charset);
			}
			
		}
		return max;
    }
};

int main(void)
{
	Solution mysolution;
	cout<<mysolution.lengthOfLongestSubstring("pwwkew");
}