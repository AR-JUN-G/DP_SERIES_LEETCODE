
int maxPoints(int days,vector<vector<int>> &points,int previous,vector<vector<int>> &dp)
{
    
    if(days==0)
    {
        int maxi=0;
        for(int index=0;index<3;index++)
        {
            if(index!=previous)
            {
                maxi=max(points[0][index],maxi);
            }
        }
        return maxi;
    }

    if(dp[days][previous]!=-1)
    {
        return dp[days][previous];
    }

    int maxi=0;
    for(int index=0;index<3;index++)
    {
        if(index!=previous)
        {
            int point=points[days][index]+maxPoints(days-1,points,index,dp);
            maxi=max(point,maxi);
        }
    }
    return dp[days][previous]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    /*
    @arg 
        n->No of Days
        points= 2d vector containing the elements row represents the days and 
        3 column represents the points of  earned for the skill  
    */
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return maxPoints(n-1, points,3,dp);
    
}
