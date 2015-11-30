// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int begin,int end)
	{
		if (isBadVersion(begin)) return begin;
		else if (isBadVersion((begin+end)/2)) return firstBadVersion((begin+end)/2,end);
		else return firstBadVersion(begin,(begin+end)/2);
	}
    int firstBadVersion(int n) {
        return firstBadVersion(1,n);
    }
};