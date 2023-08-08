#include <bits/stdc++.h> 

bool check(int index,int target,vector<int>&arr,vector<vector<int>>&dp)
{
    if(target==0)   return true;
    if(index==0)  return (arr[0]==target);
    bool pick=false;
    if(dp[index][target]!=-1)
    {
        return dp[index][target];
    }
    if(target>=arr[index])
    {
        pick=check(index-1,target-arr[index],arr,dp);
    }
    bool notPick=check(index-1,target,arr,dp);
    return dp[index][target]=pick|notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return check(n-1,k,arr,dp);
}
