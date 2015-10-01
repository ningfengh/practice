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

using namespace std;
// stack

class Solution {
public:
	int numDecodings(string s,string)
    int numDecodings(string s) {
		int length = s.size();
        return numDecodings(s,0,length);
    }
};

int main(void)
{
	Solution mysolution;
	cout<< mysolution.numDecodings("12345");

	
}