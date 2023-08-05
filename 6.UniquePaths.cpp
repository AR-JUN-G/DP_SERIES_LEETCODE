#include <bits/stdc++.h>
/*	MEMOIZATION	*/
int noOfPath(int m,int n,vector<vector<int>>&dp)
{
	if(m==0&&n==0)
	{
		return 1;
	}
	if(m<0 ||n<0)
	{
		return 0;
	}
	if(dp[m][n]!=-1)
	{
		return dp[m][n];
	}
	int left=noOfPath(m,n-1,dp);
	int right=noOfPath(m-1,n,dp);
	dp[m][n]=left+right;
	return dp[m][n];
}
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m,vector<int>(n,-1));
	/*for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i][j]=1;
		}
	}*/
	return noOfPath(m-1,n-1,dp);
}
