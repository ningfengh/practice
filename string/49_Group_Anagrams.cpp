#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include <functional>
#include <climits>
#include <sstream>
/* thought should be very slow, but it's not bad */

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

    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> >result;
		vector<pair<string,string> > strs_pair;
		vector<string> result_current;
		//PrintVector(strs);
		int i;
		for (i=0;i<strs.size();i++)
		{
			string str_sort = strs[i];
			sort(str_sort.begin(),str_sort.end());
			strs_pair.push_back(make_pair(str_sort,strs[i]));
		}
		sort(strs_pair.begin(),strs_pair.end());
		i = 0;
		result_current.clear();
		while (i<strs.size())
		{
			result_current.push_back(strs_pair[i].second);
			if (i+1<strs.size()&& strs_pair[i+1].first!=strs_pair[i].first)
			{
				
				result.push_back(result_current);
				result_current.clear();
			}
			else if (i+1>=strs.size())
				result.push_back(result_current);
			i++;
		}
		
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	
	string x[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<string> input(x,x+6);
	vector<vector<string> > result;
	result = mysolution.groupAnagrams(input);
	for (int i=0;i<result.size();i++)
		PrintVector(result[i]);

}