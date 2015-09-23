#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include <functional>
#include <climits>
using namespace std;
// use a long int, very slow
class Solution {
public:
    int romanToInt(string s) {
        int length=s.size();
		int i = 0;
		int result = 0;
		while (i<length)
		{
			if (s[i]=='I' && s[i+1] == 'V') {result+=4;i+=2;}
			else if (i!=length-1&& s[i]=='X' && s[i+1] == 'L') {result+=40;i+=2;}
			else if (i!=length-1&&s[i]=='C' && s[i+1] == 'D') {result+=400;i+=2;}
			else if (i!=length-1&&s[i]=='I' && s[i+1] == 'X') {result+=9;i+=2;}
			else if (i!=length-1&&s[i]=='X' && s[i+1] == 'C') {result+=90;i+=2;}
			else if (i!=length-1&&s[i]=='C' && s[i+1] == 'M') {result+=900;i+=2;}
			else if (s[i]=='I') {result+=1;i+=1;}
			else if (s[i]=='V') {result+=5;i+=1;}
			else if (s[i]=='X') {result+=10;i+=1;}
			else if (s[i]=='L') {result+=50;i+=1;}
			else if (s[i]=='C') {result+=100;i+=1;}
			else if (s[i]=='D') {result+=500;i+=1;}
			else if (s[i]=='M') {result+=1000;i+=1;}
		}
		return result;
    }
};

int main(void)
{
	Solution mysolution;
	cout<<mysolution.romanToInt("XXX");

}