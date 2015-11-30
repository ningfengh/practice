class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        int mytable[9] = {0};
		int i,j,m,n;
		for (i=0;i<9;i+=3)
			for (j=0;j<9;j+=3)
			{
				for (m=0;m<9;m++) mytable[m]=0;
				for (m=0;m<3;m++)
					for (n=0;n<3;n++)
					{
						if (board[i+m][j+n]-'1'>=0 && board[i+m][j+n]-'1'<=8)
						{
							if (mytable[board[i+m][j+n]-'1']==1) return false;
							else mytable[board[i+m][j+n]-'1']=1;
						}
					}
			}
			for (i=0;i<9;i++)
			{
				for (m=0;m<9;m++) mytable[m]=0;
				for (j=0;j<9;j++)
					{
						if (board[i][j]-'1'>=0 && board[i][j]-'1'<=8)
						{
							if (mytable[board[i][j]-'1']==1) return false;
							else mytable[board[i][j]-'1']=1;
						}
					}
			}	
			for (i=0;i<9;i++)
			{
				for (m=0;m<9;m++) mytable[m]=0;
				for (j=0;j<9;j++)
					{
						if (board[j][i]-'1'>=0 && board[j][i]-'1'<=8)
						{
							if (mytable[board[j][i]-'1']==1) return false;
							else mytable[board[j][i]-'1']=1;
						}
					}
			}	
			return true;	
    }
};