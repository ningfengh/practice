class Solution {
public:
	void combine(int n,int k,vector<vector<int> >& result, vector<int>& current,int current_num,int current_index,vector<int> &occupy)
	{
		
		if (current_index==k) {result.push_back(current);return;}
		for (int i=current_num+1;i<=n;i++)
		{
			current.push_back(i);
			combine(n,k,result,current,i,current_index+1,occupy);
			current.pop_back();
		}
		
	}
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
		vector<int> current;
		vector<int> occupy(n,0);
		combine(n,k,result,current,0,0,occupy);
		return result;
    }
};