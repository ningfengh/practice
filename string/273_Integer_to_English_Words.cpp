#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include <functional>
#include <climits>
#include <sstream>
/* don't forget zero, don't mis spell */

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
    
	string threeToWords(int num){
		string one[]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven",
		              "Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
		string two[]={"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
		int num1 = num%100;
		string result="";
		if (num1!=0&&num1<=19) result = one[num1-1]+result;
		else if (num1!=0) 
		{
			if (num1%10!=0)result = one[num1%10-1];
			if (result=="")result = two[num1/10-2];
			else result = two[num1/10-2] +" "+result;
		}
		int num2 = num/100;
        if (num2!=0) 
			if (result=="") result = one[num2-1]+" Hundred";
			else result = one[num2-1]+" Hundred "+result;		
		return result;	
	}
	string numberToWords(int num) {
        string result;
		if (num==0) return "Zero";
		result = threeToWords(num%1000);
		num = num/1000;
		
		if (num!=0)
		{
			if(num%1000!=0)
			{
			if (result=="") result = threeToWords(num%1000)+" Thousand";
			else result = threeToWords(num%1000)+" Thousand "+result;
			}
			num = num/1000;
			if (num!=0)
			{
				if (num%1000!=0)
				{
				if (result=="") result = threeToWords(num%1000)+" Million";
				else result = threeToWords(num%1000)+" Million "+result;
				}
				num = num/1000;
				if (num!=0)
					if (num%1000!=0)
					{
					if (result=="") result = threeToWords(num%1000)+" Billion";
					else result = threeToWords(num%1000)+" Billion "+result;
					}
			}
		}			
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	
	cout<< mysolution.numberToWords(1000001);


}