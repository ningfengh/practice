class Solution {
public:
    int reverse(int x) {
		int sign;
        if (x<0) {x = -x; sign = -1;}
		else sign = 1;
		long int result =0;
		while (x!=0)
		{
			result = result*10+x%10;
			x/=10;
		}
		if (sign*result>INT_MAX || sign*result<INT_MIN) return 0;
		else return sign*result;
    }
};