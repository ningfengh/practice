#include <string>
#include <iostream>
#include <vector>
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
    bool isValid(string s) {
		int i;
        vector <char> mystack;
		for (i=0;i<s.size();i++)
		{
			

			if (s[i]=='[' ||s[i]=='('||s[i]=='{' )
				mystack.push_back(s[i]);
			if (s[i]==']')
				if (mystack.size()==0 || mystack[mystack.size()-1]!='[') return false;
				else mystack.pop_back();
			if (s[i]==')')
				if (mystack.size()==0 || mystack[mystack.size()-1]!='(') return false;
				else mystack.pop_back();
			if (s[i]=='}')
				if (mystack.size()==0 || mystack[mystack.size()-1]!='{') return false;
				else mystack.pop_back();				
		}
		if (mystack.size()==0) return true;
		else return false;
    }
};

int main(void)
{
	Solution mysolution;
	cout<<mysolution.isValid("[{()}]");

}