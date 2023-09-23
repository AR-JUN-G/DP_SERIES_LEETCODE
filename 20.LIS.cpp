#include<bits/stdc++.h>
using namespace std;

/*  Memoiztion Solution */
int memo(vector<int>&arr,vector<vector<int>>&dp,int prevIndex,int index)
{
    if(index==arr.size())    return 0;
    if(dp[index][prevIndex+1]!=-1)    return dp[index][prevIndex+1];
    int len=memo(arr,dp,prevIndex,index+1);
    if(prevIndex==-1 ||arr[prevIndex]<arr[index]){
        len=max(len,1+memo(arr,dp,index,index+1));
    }
    return dp[index][prevIndex+1]=len;
}

/* Tabulation Method    */
int tab(vector<int>&arr)
{
    int n=arr.size();
    int maxi=1;
    vector<int>dp(n+1,1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])   dp[i]=max(dp[i],1+dp[j]);
        }
        maxi=max(maxi,dp[i]);
    }
    return maxi;
}
int main()
{
    vector<int>arr;
    int n,temp;
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
   // int result=memo(arr,dp,-1,0);
    int result=tab(arr);
    cout<<result;
    return 0;
}
