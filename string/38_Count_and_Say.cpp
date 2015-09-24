#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include <functional>
#include <climits>
#include <sstream>

/* extremly slow */
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result="1";
		for (int i=1;i<n;i++)
		{
			string result1="";
			int j=0;
			int count = 1;
			char current =  result[0];
			while (j<result.size()-1)
			{
				if (result[j+1]==result[j])
				{
					count++;
					
				}
				else
				{
					ostringstream ss;
					ss<< count;
					result1 = result1 + ss.str() + current;
					count = 1;
					current = result[j+1];
					//cout<<"aaa"<<endl;
				}
				j++;
			}
			ostringstream ss;
			ss<< count;
			result = result1+ss.str()+current;
			//cout<<i<<" "<<result<<" "<<j<<" "<<current<<endl;
		}			
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	


	cout<<mysolution.countAndSay(7);

}