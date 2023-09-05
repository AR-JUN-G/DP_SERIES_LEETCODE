class Solution {
public:
    int f(int index,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp)
    {
        if(index==prices.size() || cap==0)  return 0;
        if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];
        if(buy)
        {
            dp[index][buy][cap]=max(-prices[index]+f(index+1,0,cap,prices,dp),f(index+1,1,cap,prices,dp));
        }
        else
        {
            dp[index][buy][cap]=max(prices[index]+f(index+1,1,cap-1,prices,dp),f(index+1,0,cap,prices,dp));
        }
        return dp[index][buy][cap];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,dp);

    }
};
