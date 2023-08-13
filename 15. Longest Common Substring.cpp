#include<bits/stdc++.h>


int lcs(string &str1, string &str2){
    int m=str1.length();
    int n=str2.length();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<=m;i++)   dp[i][0]=0;
    for(int i=0;i<=n;i++)   dp[0][i]=0;
    /* ans is used to store the maximum number of repeating characters in both strings */
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            /*We are subtracting the index by -1 bcoz we are starting the loop from 1 */
            if(str1[i-1]==str2[j-1])   {
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            } 
            else    dp[i][j]=0;
        }
    }
    return ans;
}
