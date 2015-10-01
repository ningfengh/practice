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

/* DFS */

using namespace std;

class Solution {
public:
    void letterCombinations(string digits, int start, int length, string& current, map<char,vector<char> >& mymap, vector<string>& result)
	{
		if (start==length) 
		{
			result.push_back(current);
			return;
		}
		else
		{
			for (int i = 0;i<mymap[digits[start]].size();i++)
			{
				current += mymap[digits[start]][i];
				letterCombinations(digits,start+1,length,current,mymap,result);
				current = current.substr(0, current.size()-1);
			}
		}
	}
	
	vector<string> letterCombinations(string digits) {
        map <char,vector<char> > mymap;
		string current = "";
		int length = digits.size();
		vector<string> result;
		if (length==0) return result;
		mymap['2'].push_back('a');mymap['2'].push_back('b');mymap['2'].push_back('c');
		mymap['3'].push_back('d');mymap['3'].push_back('e');mymap['3'].push_back('f');
		mymap['4'].push_back('g');mymap['4'].push_back('h');mymap['4'].push_back('i');
		mymap['5'].push_back('j');mymap['5'].push_back('k');mymap['5'].push_back('l');
		mymap['6'].push_back('m');mymap['6'].push_back('n');mymap['6'].push_back('o');
		mymap['7'].push_back('p');mymap['7'].push_back('q');mymap['7'].push_back('r');mymap['7'].push_back('s');
		mymap['8'].push_back('t');mymap['8'].push_back('u');mymap['8'].push_back('v');
		mymap['9'].push_back('w');mymap['9'].push_back('x');mymap['9'].push_back('y');mymap['9'].push_back('z');
			
		letterCombinations(digits,0,length,current, mymap,result);
		
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	vector<string> result;
	int i;
	result = mysolution.letterCombinations("23");
	for (i=0;i<result.size();i++) cout<<result[i]<<endl;
}