class Solution {
public:
    int f(int i,int j,string s1,string s2,vector<vector<int>>&dp)
    {
        /*  Base cases  */

        if(i<0) return j+1;
         /*If the word 1  becomes empty then i need to insert 2 elements from the word2 to form the word1==word2(The reason why  i am doing insert bcoz by inserting elements we can have minimum operation compared to others)*/

        if(j<0) return i+1;/* I need to delete the letters  */

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j])  return  dp[i][j]=f(i-1,j-1,s1,s2,dp);
         
         return  dp[i][j]=1+min(f(i-1,j-1,s1,s2,dp),min(f(i,j-1,s1,s2,dp),f(i-1,j,s1,s2,dp)));
                                    //replace                //insert            //delete
      
      

    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        //return f(word1.length()-1,word2.length()-1,word1,word2,dp);
        for(int i=0;i<=word1.length();i++)
        {
            dp[i][0]=i;
        }
        for(int i=0;i<=word2.length();i++)
        {
            dp[0][i]=i;
        }
         for(int i=1;i<=word1.length();i++)
        {
            for(int j=1;j<=word2.length();j++)
            {
                if(word1[i-1]==word2[j-1]) {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }

        return dp[word1.length()][word2.length()];
    }
};
