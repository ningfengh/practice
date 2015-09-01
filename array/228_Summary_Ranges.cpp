#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>

using namespace std;

void PrintVector(vector<int>& in)
{
	int i;
	for (i=0;i<in.size();i++)
		cout<<in[i]<<" ";
	cout<<endl;
}
string to_string(int i)
{
	stringstream ss;
	ss<<i;
	return ss.str();
}

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i;
		int begin,end;
		int length = nums.size();
		vector<string> result;
		if (nums.size()==0) return result;
		begin = nums[0];
		end = nums[0];
		for (i=1;i<length;i++)
		{
			if (nums[i]-nums[i-1]==1)
				end = nums[i];
			else
			{
				if (begin==end) result.push_back(to_string(begin));
				else result.push_back(to_string(begin)+"->"+to_string(end));
				begin = nums[i];
				end = nums[i];
			}
		}
		if (begin==end) result.push_back(to_string(begin));
				else result.push_back(to_string(begin)+"->"+to_string(end));
		return result;
    }
};


int main(void)
{

	int a[]={0,1};
	int i;
	Solution mysolution;
	vector<int>  vec_a(a,a+2);
	vector<string> result;
	result = mysolution.summaryRanges(vec_a);
	for (i=0;i<result.size();i++)
		cout<<result[i]<<endl;
	
	

}