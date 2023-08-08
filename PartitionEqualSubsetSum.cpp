#include<bits/stdc++.h>

bool f(vector<int> &arr,int index,int target,vector<vector<int>>&dp)
{
	if(target==0)	return true;
	if(index==0)	return arr[0]==target;
	if(dp[index][target]!=-1)	return dp[index][target];
	bool pick=false;
	if(arr[index]<=target)
	{
		pick=f(arr,index-1,target-arr[index],dp);
	}
	bool notPick=f(arr,index-1,target,dp);
	return dp[index][target]=pick|notPick;

}
bool canPartition(vector<int> &arr, int n)
{
	int sum=0;
	for(auto c:arr)
	{
		sum+=c;
	}
	if(sum%2!=0)
	{
		return false;
	}
	vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
	return f(arr,n-1,sum/2,dp);

}
