/*  https://bit.ly/3q5rlUY  */

#include <bits/stdc++.h>

using namespace std;

int maxSum(vector<int>& nums, int index, vector<int>& dp) {
  // This function calculates the maximum sum of non-adjacent elements
  // in the array.

  if (index == 0) {
    // If the current index is 0, then the maximum sum is simply the element at that index.
    return nums[index];
  }

  if (index < 0) {
    // If the current index is less than 0, then the maximum sum is 0.
    return 0;
  }

  if (dp[index] != -1) {
    // If the dp array already contains the maximum sum for the current index, then
    // return the value from the dp array.
    return dp[index];
  }

  // The maximum sum of non-adjacent elements in the array
  // is the maximum of the following two values:
  //   * The element at the current index, plus the maximum sum of non-adjacent elements
  //     in the array starting from the index two positions before.
  //   * The maximum sum of non-adjacent elements in the array starting from the index one position before.

  int maxSum1 = nums[index] + maxSum(nums, index - 2, dp);
  int maxSum2 = maxSum(nums, index - 1, dp);

  dp[index] = max(maxSum1, maxSum2);
  // Store the maximum sum of non-adjacent elements in the array
  // in the dp array.

  return dp[index];
}

int maximumNonAdjacentSum(vector<int> &nums) {
  // This function takes the array of numbers as input.

  vector<int> dp(nums.size(), -1);
  // Initialize the dp array to -1.

  int result = maxSum(nums, nums.size() - 1, dp);
  // Calculate the maximum sum of non-adjacent elements in the array.

  return result;
}
