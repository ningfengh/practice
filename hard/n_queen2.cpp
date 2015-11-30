class Solution {
public:
	void totalNQueens(int n,vector<int>& queen_array, int& sum, int queen_idx)
	{
		if (queen_idx==n) {sum++;return;}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<queen_idx;j++)
			{
				if (i==queen_array[j]||i-queen_array[j]==queen_idx-j|| i-queen_array[j]==j-queen_idx)
					break;
			}
			if (j==i-1)
			{
				queen_array[queen_idx]=i;
				totalNQueens(n,queen_array,sum,queen_idx+1);
			}
		}
	}
    int totalNQueens(int n) {
        int sum=0;
		vector <int> queen_array(n,0);
		totalNQueens(n,queen_array,sum,0);
    }
};