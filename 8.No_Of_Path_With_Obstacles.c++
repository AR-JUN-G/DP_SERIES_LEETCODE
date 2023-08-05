class Solution {
public:
    int pathWithObstacles(int m,int n,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(m>=0 && n>=0 && grid[m][n]==1)
        {
            return 0;
        }
        if(m==0 && n==0)
        {
            return 1;
        }
        if(m<0 || n<0)
        {
           return 0;
        }
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        int up=pathWithObstacles(m-1,n,grid,dp);
        int left=pathWithObstacles(m,n-1,grid,dp);
        return dp[m][n]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,-1));
        return pathWithObstacles(row-1,col-1,obstacleGrid,dp);
    }
};
