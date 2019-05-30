class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minimum = INT_MAX;
        int res = 0;
        
        for (int i = 0; i < prices.size(); i++)
        {
            minimum = min(prices[i], minimum);
            res = max(res, prices[i] - minimum);
        }
        
        return res;
    }
};