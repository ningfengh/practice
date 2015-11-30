class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        vector<pair<int,int> > stencil;
		stencil.push_back(make_pair(-1,-1));
		stencil.push_back(make_pair(-1,0));
		stencil.push_back(make_pair(-1,1));
		stencil.push_back(make_pair(0,1));
		stencil.push_back(make_pair(0,-1));
		stencil.push_back(make_pair(1,-1));
		stencil.push_back(make_pair(1,0));
		stencil.push_back(make_pair(1,1));
		int m = board.size();
		int n = board[0].size();
		int count;
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				count = 0;
				for (int k=0;k<8;k++)
				{
					int new_x = i+stencil[k].first;
					int new_y = j+stencil[k].second;
					if (new_x>=0 && new_x<m && new_y>=0 && new_y<n) 
					{
						if (board[new_x][new_y]==1 || board[new_x][new_y]==-1) count++;
					}

				}

				if (board[i][j]==1 && ((count<2)||(count>3))) board[i][j]=-1;
				if (board[i][j]==0 && count>3) board[i][j] = -2;
				
			}
		}
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				if (board[i][j]==-1) board[i][j]=0;
				if (board[i][j]==-2) board[i][j]=1;
			}
		}
		return;
    }
};