class Solution {
public:
    int f(int index,int buy,vector<int>& prices,vector<vector<int>>&dp)
    {
        if(index==prices.size())   return 0;
        /*  One person can buy a stock or he can skip the stock and buy on another day */
        /*I can buy the stock if the buy==1 else i cant buy i need to sell(else condition) and after that i can buy the stock   */

        int profit=0;
        if(dp[index][buy]!=-1)  return dp[index][buy];
        if(buy)
        {
            /* If I bought the stock my profit amount will be reduced 
                Else i not prefer to buy the stock on that day and i go for another day with buy==1 */
            dp[index][buy]=max(-prices[index]+f(index+1,0,prices,dp),f(index+1,1,prices,dp));
        }
        else
        {
            /* If I Sell the stock my profit amount will be increased 
                Else i not prefer to sell the stock on that day and i go for another day with buy==0*/
            dp[index][buy]=max(prices[index]+f(index+1,1,prices,dp),f(index+1,0,prices,dp));
        }
        return dp[index][buy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};
