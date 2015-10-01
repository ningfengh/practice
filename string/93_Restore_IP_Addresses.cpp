#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <set>
#include <functional>
#include <climits>
#include <sstream>


using namespace std;

class Solution {
public:

	void restoreIpAddresses(string s,int start,int num,string &current, vector <string> &result)
	{
		int i;
		int tmp;

		if (num==3)
		if (start>=s.size()||start<s.size()-3||(s[start]=='0'&&start!=s.size()-1)) return;	
		else 
		{
			tmp=0;
			i = start;
			while (i<s.size())
			{
				tmp = tmp*10+s[i]-'0';
				i++;
			}
			if (tmp<=255) 
			{
				current+=s.substr(start,s.size()-start);
				result.push_back(current);
				return;
			}
		}
		else
		{
			tmp = 0;
			if (s[start]=='0')
			{
				string backup = current;
				current+=s.substr(start,1);
				current+='.';
				restoreIpAddresses(s,start+1,num+1,current,result);
				current = backup;
			}
			else
			for (i=0;i<3;i++)
			{
				if (start+i>=s.size())
					return;
				else
				{
					tmp = tmp*10+s[i+start]-'0';
					if (tmp<=255)
					{
						string backup = current;
						current+=s.substr(start,i+1);
						current+='.';
						restoreIpAddresses(s,start+i+1,num+1,current,result);
						current = backup;
					}
				}
			}
		}
		 	
	}
	
    vector<string> restoreIpAddresses(string s) {
        vector <string> result;
		string current ="";
		restoreIpAddresses(s,0,0,current,result);
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	vector<string> result;
	int i;
	result = mysolution.restoreIpAddresses("010010");
	cout<<result.size()<<endl;
	for (i=0;i<result.size();i++) cout<<result[i]<<endl;
}