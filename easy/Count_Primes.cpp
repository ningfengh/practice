class Solution {
public:
    int countPrimes(int n) {
        boolean[] isPrime = new boolean[n];
		int i;
		for (i=2;i<n;i++) isPrime[i] = true;
		for (i=2;i*i<n;i++){
			if (!isPrime[i]) continue;
			for (int j=i*i;j<n;j+=i){
				isPrime[j] = false;
			}
		}
		int count = 0;
		for (i=2;i<n;i++) if(isPrime[i]) count++;
		return count;
    }
};