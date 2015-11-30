class Solution {
public:
    string convertToTitle(int n) {
        string result;
		n=n-1;
		while (n!=0)
		{
			char tmp = 'A' + n%26;
			result+= tmp;
			n = n/26;
		}
    }
};