#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include <functional>
#include <climits>

/* this version only supports one dot */

/* there are several dots in the test vectors   1.0.1*/

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int length1 = version1.size();
		int length2 = version2.size();
		int major1 = 0, major2 = 0,minor1 = 0,minor2= 0;
		int i=0;
		while (version1[i]!='.'&&i<length1)
		{
			major1 = major1*10+version1[i]-'0';
			i++;
		}
		i++;
		while (i<length1)
		{
			minor1 = minor1*10+version1[i]-'0';
			i++;
		}
		
		i=0;
		while (version2[i]!='.'&&i<length2)
		{
			major2 = major2*10+version2[i]-'0';
			i++;
		}
		i++;
		while (i<length2)
		{
			minor2 = minor2*10+version2[i]-'0';
			i++;
		}		
		if (major1>major2) return 1;
		else if (major1<major2) return -1;
		else if (minor1>minor2) return 1;
		else if (minor1<minor2) return -1;
		else return 0;
    }
};

int main(void)
{
	Solution mysolution;
	


	cout<<mysolution.compareVersion("11.4","11.23");

}