#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        string result;
		int length = s.size();
		if (numRows==1) return s;
		int i,j;
		for (i=0;i<length;i+=(numRows-1)*2)
			result = result+s[i];
		for (i=1;i<numRows-1;i++)
		{
			for (j=i;j<length;j+=(numRows-1)*2)
			{
				result = result+s[j];
				if (j+(numRows-1)*2-2*i<length)
					result = result+s[j+(numRows-1)*2-2*i];
			}
		}
		for (i=numRows-1;i<length;i+=(numRows-1)*2)
			result = result+s[i];		
		
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	cout<<mysolution.convert("A",1);

}