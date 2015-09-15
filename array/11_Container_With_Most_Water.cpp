#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>



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
    int maxArea(vector<int>& height) {
        int l(0),r=height.size()-1,result(0);
		while (l<r)
		{
			if (height[r]<height[l])
			{
				if (result<height[r]*(r-l))
				{
					result = height[r]*(r-l);
				}
				int pivot = height[r--];
				while (height[r]<=pivot && l<r) --r;
				
			}
			else
			{
				if (result<height[l]*(r-l))
				{
					result = height[l]*(r-l);
				}
				int pivot = height[l--];
				while (height[l]<=pivot && l<r) ++l;	
						
			}
		}
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	int x[]={5,6,0,1,2,3,4};
	vector<int> input(x,x+7);

	cout<<mysolution.maxArea(input);
	
	
}