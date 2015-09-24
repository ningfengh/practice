#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include <functional>
#include <climits>

/* still wrong , cannot compare 1.0 and 1 */

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int length1 = version1.size();
		int length2 = version2.size();
		int v1=0,v2=0;
		int i=0,j=0;
		
		while (i<length1 && j<length2)
		{
			v1 = 0 ; v2 = 0;
			while (version1[i]!='.'&&i<length1)
			{
				v1 = v1*10+version1[i]-'0';
				i++;
			}
		
			while (version2[j]!='.'&&j<length2)
			{
				v2 = v2*10+version2[j]-'0';
				j++;
			}
			if (v1>v2) return 1; 
			if (v1<v2)return -1;
			i++;
			j++;
		}

		if (i>=length1 && j>=length2) return 0;
		else if (i>=length1) 
		{
			v2 = 0;
			while (j<length2)
			{
			while (version2[j]!='.'&&j<length2)
			{
				v2 = v2*10+version2[j]-'0';
				j++;
			}
			if (v2!=0) return -1;
			j++;
			}
			return 0;
		}
		else 
		{
			v1 = 0;
			while (i<length1)
			{
			while (version1[i]!='.'&&i<length1)
			{
				v1 = v1*10+version1[i]-'0';
				i++;
			}
			if (v1!=0) return 1;
			i++;
			}
			return 0;			
		}
		
		
    }
};

int main(void)
{
	Solution mysolution;
	


	cout<<mysolution.compareVersion("11.23.0","11.23");

}