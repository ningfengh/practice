class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profit(prices.size(),0);
		if (prices.size()<3) return 0;
		else if (prices.size()==3) return max(0,prices[1]-prices[0]);
		for (int i=1;i<prices.size();i++){
			int max_profit = 0;
			for (int j=i-1;j>=0;j--){
				int pro = prices[i]-prices[j];
				if (j-2>=0) pro+=profit[j-2];
				if (pro>max_profit) max_profit = pro;
			}
			profit[i] = max_profit;
		}
    }
	return profit[prices.size()-1];
};