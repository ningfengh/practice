#include <iostream>
#include <vector>
using namespace std;
void PrintVector(vector<int>& in)
{
	int i;
	for (i=0;i<in.size();i++)
		cout<<in[i]<<endl;
	cout<<endl;
}
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		int carry = 0;
		int length = digits.size(),i;
		vector<int> digits_out(length);
        digits_out[length-1] = digits[length-1]+1;
		if (digits_out[length-1]>=10)
		{
			carry = 1;
			digits_out[length-1]-=10;
		}
		else carry = 0;
		for (i=length-2;i>=0;i--)
		{
			digits_out[i]= digits[i]+carry;
			if (digits_out[i]>=10)
			{
				carry = 1;
				digits_out[i]-=10;
			}
			else carry =0;
		}
		if (carry ==1)
			digits_out.insert(digits_out.begin(),1);
		return digits_out;
    }
};


int main(void)
{
	Solution mysolution;
	int tmp[]={9};
	vector<int> input(tmp,tmp+1);
	vector<int> output;
	output= mysolution.plusOne(input);
	PrintVector(output);
	return 0;
}