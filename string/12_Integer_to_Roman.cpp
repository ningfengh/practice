#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include <functional>
#include <climits>
#include <sstream>


using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int one,two,three,four;
		string result="";
		one = num%10;
		switch (one) {
			case 1:
				result = "I"+result;
				break;
			case 2:
				result = "II"+result;
				break;
			case 3:
				result = "III"+result;
				break;
			case 4:
				result = "IV"+result;
				break;
			case 5:
				result = "V"+result;
				break;
			case 6:
				result = "VI"+result;
				break;
			case 7:
				result = "VII"+result;
				break;
			case 8:
				result = "VIII" +result;
				break;
			case 9:
				result = "IX" +result;
				break;			
		}
		num = num/10;
		if (num==0) return result;

		two = num%10;
		switch (two) {
			case 1:
				result = "X"+result;
				break;
			case 2:
				result = "XX"+result;
				break;
			case 3:
				result = "XXX"+result;
				break;
			case 4:
				result = "XL"+result;
				break;
			case 5:
				result = "L"+result;
				break;
			case 6:
				result = "LX"+result;
				break;
			case 7:
				result = "LXX"+result;
				break;
			case 8:
				result = "LXXX" +result;
				break;
			case 9:
				result = "XC" +result;
				break;			
		}
		num = num/10;
		if (num==0) return result;

		three = num%10;
		switch (three) {
			case 1:
				result = "C"+result;
				break;
			case 2:
				result = "CC"+result;
				break;
			case 3:
				result = "CCC"+result;
				break;
			case 4:
				result = "CD"+result;
				break;
			case 5:
				result = "D"+result;
				break;
			case 6:
				result = "DC"+result;
				break;
			case 7:
				result = "DCC"+result;
				break;
			case 8:
				result = "DCCC" +result;
				break;
			case 9:
				result = "CM" +result;
				break;			
		}
		num = num/10;
		if (num==0) return result;

		four = num%10;
		switch (four){
			case 1:
				result = "M"+result;
				break;
			case 2:
				result = "MM"+result;
				break;
			case 3:
				result = "MMM"+result;
				break;
			
		}
		return result;		
    }
};

int main(void)
{
	Solution mysolution;
	


	cout<<mysolution.intToRoman(1234);

}