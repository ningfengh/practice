#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
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
	void swap(vector<int>& nums, int i, int j)
	{
		int temp;
		temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
    void sortColors(vector<int>& nums) {
        int head=0,tail=nums.size()-1,pt=0;
		if (tail==head) return;
		while(nums[head]==0) 
		{
			head++;
			pt++;
		}
		cout<<head<<" "<<pt<<" "<<tail<<endl;
		while (pt<=tail)
		{
			while(nums[tail]==2) tail--;
			while(nums[head]==0) 
			{	head++;
				if (pt<head) pt=head;
			}
			if (pt>tail) break;
			cout<<head<<" "<<pt<<" "<<tail<<endl;
			if (nums[pt]==2)
				swap(nums,pt,tail);
			else if (nums[pt]==0)
				swap(nums,pt,head);
			else if (nums[pt]==1)
				pt++;
			PrintVector(nums);
		}
		
		PrintVector(nums);
		
    }
};

int main(void)
{
	Solution mysolution;
	int x[] = {0,2} ;
	vector<int> input(x,x+2);
	mysolution.sortColors(input);
	PrintVector(input);


}