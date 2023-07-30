class Solution {
public:

    /* 
    ** Recursive function to calculate the number of ways to reach the nth stair.
    **
    ** Args:
    **     n: The number of the stair.
    **
    ** Returns:
    **     The number of ways to reach the nth stair.
    */
    int numberOfSteps(int n) {
        
        /* 
        ** Base cases: There is only one way to reach the first and second stairs.
        */
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return 1;
        }

        /* 
        ** Recursively calculate the number of ways to reach the stair.
        */
        return numberOfSteps(n - 1) + numberOfSteps(n - 2);
    }

    /* 
    ** Dynamic programming function to calculate the number of ways to reach the nth stair.
    **
    ** Args:
    **     n: The number of the stair.
    **
    ** Returns:
    **     The number of ways to reach the nth stair.
    */
    int climbStairs(int n) {
        
        /* 
        ** Initialize a vector to store the number of ways to reach each stair.
        */
        std::vector<int> dp(n + 1, 0);

        /* 
        ** Set the values for the first and second stairs.
        */
        dp[0] = 1;
        dp[1] = 1;

        /* 
        ** Iterate through the rest of the stairs and fill in the values.
        */
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        /* 
        ** Return the value for the nth stair.
        */
        return dp[n];
    }
};
