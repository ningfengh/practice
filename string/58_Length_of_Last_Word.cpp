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
    int lengthOfLastWord(string s) {
        int length = s.size();
		int i = length-1;
		while (s[i]==' '&&i>=0) i--;
		int result =0;
		while (s[i]!=' ' &&i>=0){i--;result++;}
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	


	cout<<mysolution.lengthOfLastWord("a");

}