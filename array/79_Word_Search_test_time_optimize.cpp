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
	bool search(vector<vector<char> >& board,string& word,int start,int length, int i,int j, int m, int n)
	{
		bool flag = false;
		char tmp;
		if (word[start]!=board[i][j])
			return false;
		else if (start == length-1) 
		{
			return true;
		}
		else 
		{
			tmp = board[i][j];
			board[i][j]='*';
			if (i>0) // left
			{
				flag = search(board,word,start+1,length,i-1,j,m,n);
			}
			if (!flag && i<m-1) //right
			{
				flag = search(board,word,start+1,length,i+1,j,m,n);
	    	}
			if (!flag && j>0) // top
			{
				flag = search(board,word,start+1,length,i,j-1,m,n);
			}			
			if (!flag && j<n-1)
			{
				flag = search(board,word,start+1,length,i,j+1,m,n);
			}
			board[i][j]=tmp;
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
				flag = search(board,word,0,length,i,j,m,n);
				if (flag) return true;
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