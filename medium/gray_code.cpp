class Solution {
public:
    vector<int> grayCode(int n) {
        vector <int> result;
		result.push_back(0);
		int stride = 1;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<stride;j++)
				result.push_back(result[stride-1-j]+stride);
			stride*=2;
		}
		return result;
    }
};