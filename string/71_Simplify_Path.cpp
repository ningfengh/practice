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
    string simplifyPath(string path) {
        stack <string> path_stack;
		string current;
		string result;
		path = path +'/';
		for (int i=0;i<path.size();i++)
		{
			
			if (path[i]=='/') 
			{
				
				if (current=="..") 
				{
					if (!path_stack.empty())
					{
						path_stack.pop();
					}
				}
				else if (current!=""&&current!=".") path_stack.push(current);
						current = "";
				continue;
			}
			else
			{
				current+=path[i];
			}

			
		}
		
		if (path_stack.empty()) 
		{
			result = "/";
			if (current!=".")
				result = result+current;
		}
		
		while (!path_stack.empty())
		{
			
			result = '/'+ path_stack.top()+result;
			path_stack.pop();
		}		
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	cout<< mysolution.simplifyPath("/...");

	
}