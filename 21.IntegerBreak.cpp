/* Video Link https://www.youtube.com/watch?v=nSbnoNfHPG0&t=260s  */
class Solution {
public:
    int f(vector<int>&dp,int n)
    {
        if(n==1)    return 1;
        if(dp[n]!=-1)   return dp[n];
        for(int i=1;i<n;i++)
        {
            dp[n]=max(dp[n],(i*f(dp,n-i)));
        }
        return dp[n];
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return f(dp,n);
    }
};
