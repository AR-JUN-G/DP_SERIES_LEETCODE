class Solution {
public:
    /*  The Problem is similar to longest common subsequence of the string  */
    int f(vector<int>& v1,vector<int>v2,int index1,int index2,vector<vector<int>>&dp)
    {
        if(index1==v1.size() || index2==v2.size())  return 0;
        if(v1[index1]==v2[index2])  return 1+f(v1,v2,index1+1,index2+1,dp);
        if(dp[index1][index2]!=-1)  return dp[index1][index2];
        return dp[index1][index2]=max(f(v1,v2,index1+1,index2,dp),f(v1,v2,index1,index2+1,dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        for(int i=0;i<=nums1.size();i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<=nums2.size();j++)
        {
            dp[0][j]=0;
        }
        for(int i=1;i<=nums1.size();i++)
        {
            for(int j=1;j<=nums2.size();j++)
            {
                if(nums1[i-1]==nums2[j-1])   dp[i][j]=1+dp[i-1][j-1];
                else    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};
