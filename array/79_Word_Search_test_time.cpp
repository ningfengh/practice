#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void PrintVector(vector<int>& in)
{
	int i;
	for (i=0;i<in.size();i++)
		cout<<in[i]<<" ";
	cout<<endl;
}
string to_string(int i)
{
	stringstream ss;
	ss<<i;
	return ss.str();
}

class Solution {
public:
	bool search(vector<vector<char> >& board,vector<vector<bool> >& occupy,string& word,int start,int i,int j)
	{
		int length = word.size();
		int m = board.size();    // number of rows
		int n = board[0].size();   // number of columns
		bool flag = false;
		cout<<"start="<<start<<endl;
		//cout<<"i="<<i<<endl;
		//cout<<"j="<<j<<endl;
		//cout<<"length="<<length<<endl;
		if (start == length) 
		{
			return true;
		}
		else 
		{
			if (i>0 && occupy[i-1][j]==0 && board[i-1][j]==word[start]) // left
			{
				occupy[i-1][j]=1;
				flag = search(board,occupy,word,start+1,i-1,j);
				occupy[i-1][j]=0;
			}
			if (i<m-1 && occupy[i+1][j]==0 && board[i+1][j]==word[start]) //right
			{
				occupy[i+1][j]=1;
				flag = search(board,occupy,word,start+1,i+1,j);
				occupy[i+1][j]=0;
	    	}
			if (j>0 && occupy[i][j-1]==0 && board[i][j-1]==word[start]) // top
			{
				occupy[i][j-1]=1;
				flag = search(board,occupy,word,start+1,i,j-1);
				occupy[i][j-1]=0;
			}			
			if (j<n-1 && occupy[i][j+1]==0 && board[i][j+1]==word[start])
			{
				occupy[i][j+1]=1;
				flag = search(board,occupy,word,start+1,i,j+1);
				occupy[i][j+1]=0;
			}
			if (flag) return true;
			else return false;
		}
		
			
	}
    bool exist(vector<vector<char> >& board, string word) {
		int length = word.size();   // length of the word 
		int m = board.size();    // number of rows
		int n = board[0].size();   // number of columns
		int i,j;
		vector<vector<bool> > occupy(m,vector<bool> (n,0));
		
		bool flag = false;
		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				//cout<<board[i][j]<<endl;
				if (word[0]==board[i][j])
				{
						occupy[i][j]=1;
						flag = search(board,occupy,word,1,i,j);
						occupy[i][j]=0;
						if (flag) return true;
						
				}
			}
		}
        return false;
    }
};


int main(void)
{
	char board_char[3][4]={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	string board_string[]=
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaab"}; 
	
	vector<vector<char> > board;
	Solution mysolution;
	string word = "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	int i;
	int n = board_string[0].size();
	int m = 30;
	for (i=0;i<m;i++)
	{
		vector<char> tmp(&board_string[i][0],&board_string[i][0]+n);
		board.push_back(tmp);
	}

	
	cout<<mysolution.exist(board,word)<<endl;	

}