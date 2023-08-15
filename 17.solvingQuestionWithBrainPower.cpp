class Solution {
public:

    long long g(vector<vector<int>>&q,int brainPowerIndex,vector<long>&dp)
    {
        if(brainPowerIndex>=q.size())    return 0;
        if(dp[brainPowerIndex]!=-1) return dp[brainPowerIndex];
        long long pick=q[brainPowerIndex][0]+g(q,brainPowerIndex+q[brainPowerIndex][1]+1,dp);
        long long notPick=g(q,brainPowerIndex+1,dp);
        return dp[brainPowerIndex]=max(pick,notPick);
    }


    long long mostPoints(vector<vector<int>>& questions) {
        vector<long>dp(questions.size(),-1);
        return g(questions,0,dp);
    }
};
