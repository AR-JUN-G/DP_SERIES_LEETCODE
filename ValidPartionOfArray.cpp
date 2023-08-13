class Solution {
public:
    bool f(vector<int>&nums,vector<int>&dp,int index)
    {
        if(index==nums.size())    return true;
        if(dp[index]!=-1)   return dp[index];
        /*  case 1: Checking 2 elements are equal */
        if(index+1<nums.size() && nums[index]==nums[index+1])
        {
            if(f(nums,dp,index+2))return dp[index]=true;
            /*case 2: First 2 elements are equal checking the 3rd ELement   */
            if(index+2<nums.size() && nums[index]==nums[index+2])
            {
                if(f(nums,dp,index+3))  return dp[index]=true;
            }

        }
        /*Case 3: Checking 3 elements are differ by 1 */
        if(index+2<nums.size() && nums[index+1]==nums[index]+1 && nums[index+2]==nums[index]+2)
        {
            if(f(nums,dp,index+3)) return dp[index]=true;
        }
        return dp[index]=false;


    }
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums,dp,0);
    }
};
