#include <bits/stdc++.h> 
int minimum(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&values,int n)
{
	if(i==n-1)
	{
		return values[n-1][j];
	}
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	int down=values[i][j]+minimum(i+1,j,dp,values,n);
	int diagonal=values[i][j]+minimum(i+1,j+1,dp,values,n);
	return dp[i][j]=min(down,diagonal);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>>dp(n,vector<int>(n,-1));
	return minimum(0,0,dp,triangle,n);
}
