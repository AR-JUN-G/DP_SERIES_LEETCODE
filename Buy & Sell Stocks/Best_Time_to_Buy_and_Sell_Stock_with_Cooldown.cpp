class Solution {
public:
    int f(vector<int>&prices,int index,int buy,vector<vector<int>>&dp)
    {
        if(index>=prices.size())    return 0;
        if(dp[index][buy]!=-1)  return dp[index][buy];
        if(buy){
            dp[index][buy]=max(-prices[index]+f(prices,index+1,0,dp),f(prices,index+1,1,dp));
        }
        else
        {
            dp[index][buy]=max(prices[index]+f(prices,index+2,1,dp),f(prices,index+1,0,dp));
        }
        return dp[index][buy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return f(prices,0,1,dp);
    }
};
