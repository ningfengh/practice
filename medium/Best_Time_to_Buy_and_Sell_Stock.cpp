class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profit(prices.size(),0);
		prices.push_back(0);
		if (prices.size()<3) return 0;
		else if (prices.size()==3) return max(0,prices[1]-prices[0]);
		for (int i=1;i<prices.size()-1;i++){
			if (prices[i]>=prices[i-1]) profit[i] = profit[i-1]+prices[i]-prices[i-1];
			else if (prices[i+1]>=prices[i]) 
				if (i==1 || (prices[i+1]-prices[i])>(profit[i-1]-profit[i-2]))
				{
					profit[i] = (i==1)?0:profit[i-2]; 
				}
				else 
				{
					profit[i] = profit[i-1]; i++;
				}			
			else  profit[i] = profit[i-1];
			cout<<i<<" "<<profit[i]<<endl;
		}
		return profit[prices.size()-2];
    }
};