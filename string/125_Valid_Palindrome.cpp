#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include <functional>
using namespace std;

void PrintVector(vector<char>& in)
{
	int i;
	for (i=0;i<in.size();i++)
		cout<<in[i]<<" ";
	cout<<endl;
}


class Solution {

public:
    bool isPalindrome(string s) {
		int i=0;
		
		while(i < s.size()){
			s[i] = tolower(s[i]);
 			if (!isalnum(s[i]) || s[i] == ' '){
				s.erase(i,1);
			}else
				i++;
			
		}
		int length = s.size();
		for (i=0;i<s.size()/2;i++)
			if (s[i]!=s[length-i-1]) return false;
		return true;
    }
};

int main(void)
{
	Solution mysolution;
	cout<<mysolution.isPalindrome("a.");

}