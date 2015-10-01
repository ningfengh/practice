#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include <functional>
#include <climits>
#include <sstream>
/* DP  */

using namespace std;
void PrintVector(vector<unsigned short>& in)
{
	int i;
	for (i=0;i<in.size();i++)
		cout<<in[i]<<" ";
	cout<<endl;
}
class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size();
		int l2 = num2.size();
		vector <unsigned short> result;
		int i,j;
		for (i=0;i<l1;i++)
		{
			unsigned short carrier = 0;
			for (j=0;j<l2;j++)
			{
				unsigned short n1 = num1[l1-i-1]-'0';
				unsigned short n2 = num2[l2-j-1]-'0';
				unsigned short r = n1*n2;
	
				carrier+= r/10;
	
				if (result.size()<j+1+i) 
				{
					result.push_back(r%10);
				}
				
				else {
					result[j+i]+=r%10;
					if (result[j+i]>=10) {carrier+=result[j+i]/10;result[j+i]%=10;}
				}
				if (result.size()<j+2+i && carrier!=0) result.push_back(carrier);
				else
				{
					result[j+1+i]+=carrier;
				}
			
				carrier=0;
				//PrintVector(result);
			}
		}	
		string res="";
		i = result.size()-1;
		while (result[i]==0) i--;
		if (i<0) return "0";
		else
		for (i=0;i<result.size();i++)
		{
			char tmp = '0'+(char)result[i];
			res = tmp+res;
		}
		return res;
    }
};





int main(void)
{
	Solution mysolution;
	cout<<mysolution.multiply("96","313");
}