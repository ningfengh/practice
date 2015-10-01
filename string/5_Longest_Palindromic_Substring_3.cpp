#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include <functional>
#include <climits>
#include <sstream>
/* DP  */

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
        int length = s.size();
		bool table[1000][1000]={false};
		int i,j;
		int max = 0;
		string max_string="";
		if (length<=1) return s;
		if (length==2&& s[0]==s[1]) return s;
		for (i=0;i<length;i++) table[i][i] = true;
		for (i=0;i<length-1;i++) 
		if (s[i]==s[i+1])
		{		table[i][i+1] = true;
                if (max==0) {
					max = 1;
					max_string = s.substr(i,2);
				}	
		}
		
		
		for (j=1;j<=length;j+=1)
			for (i=0;i<length-j;i++)
			{
				if (table[i+1][i+j-1]==true && s[i]==s[i+j])
				{
						table[i][i+j] = true;
						if (j+1>max)
						{	max = j+1;
							max_string = s.substr(i,j+1);
						}
				}
				/*
				for (int k1=0;k1<length;k1++)
				{
					for (int k2=0;k2<length;k2++)
					{
						cout<<table[k1][k2]<<" ";
					}
					cout<<endl;
				}
				cout<<endl;
				*/
			}
		return max_string;
    }
};

int main(void)
{
	Solution mysolution;
	cout<<mysolution.longestPalindrome("abb");
	//cout<< mysolution.longestPalindrome("abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa");


}