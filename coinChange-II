class Solution {
public:

    int f(int amount,vector<int>&coins,int index,vector<vector<int>>&dp)
    {
       
        if(amount==0)   return 1;
        if(amount<0)    return 0;
        if(index==coins.size())   return 0;
        if(dp[index][amount]!=-1)   return dp[index][amount];
        int pick=0,notPick;
        if(pick<=coins[index])  pick=f(amount-coins[index],coins,index,dp);
        notPick=f(amount,coins,index+1,dp);
        return dp[index][amount]= pick+notPick;
    }
    int change(int amount, vector<int>& coins) {
      vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
      return f(amount,coins,0,dp);  
    }
};
