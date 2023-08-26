#include<bits/stdc++.h>

/*                   Memoization
int lis(int arr[],int prevIndex,int index,int length,vector<vector<int>>&dp)
{
    if(index==length)   return 0;
    int len=0+lis(arr,prevIndex,index+1,length,dp);
    if(dp[index][prevIndex+1]!=-1) return dp[index][prevIndex+1];
    if(prevIndex==-1||arr[prevIndex]<arr[index])
    {
        len=max(len,1+lis(arr,index,index+1,length,dp));
    }
    return dp[index][prevIndex+1]=len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return lis(arr,-1,0,n,dp);
}
*/

/*  Tabulation */
int longestIncreasingSubsequence(int arr[],int n)
{
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int index=n-1;index>=0;index--)
    {
        for(int prev=index-1;prev>=-1;prev--)
        {
            int len=0+dp[index+1][prev+1];
            
            if(prev==-1||arr[prev]<arr[index])
            {
                len=max(len,1+dp[index+1][index+1]);
            }
            dp[index][prev+1]=len;
        }
    }
    return dp[0][0];
}
