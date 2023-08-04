class Solution {
public:
    int minimum(int m,int n,vector<vector<int>>&gridValues,vector<vector<int>>&dp)
    {
        if(m==0&&n==0)
        {
            return gridValues[0][0];
        }
        if(m<0 || n<0)
        {
            return 1e9;
        }
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        int top=gridValues[m][n]+minimum(m-1,n,gridValues,dp);
        int left=gridValues[m][n]+minimum(m,n-1,gridValues,dp);
        dp[m][n]=min(top,left);
        return dp[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        cout<<m<<" "<<n;

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return minimum(m-1,n-1,grid,dp);
    }
};
