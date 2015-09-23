#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
		bool result=false;
		if (num==0) return false;
        if (num==1) return true;
		if (num%2==0) result = isUgly(num/2); 
		if (result) return true;
		if (num%3==0) result = isUgly(num/3);
		if (result) return true;
		if (num%5==0) result = isUgly(num/5);
		if (result) return true;
		return false;
    }
};

int main(void)
{
	Solution mysolution;
	
	cout<<mysolution.isUgly(7);

	return 1;
}