/*  House Robber 2*/

class Solution {
public:
  int maxRob(vector<int>& nums, int end, int index, vector<int>& dp) {
    // This function calculates the maximum amount of money that can be robbed
    // from the array starting from the index `index` and ending at the index `end`.

    if (index == end) {
      // If the current index is equal to the end index, then the maximum amount of money that can be robbed is simply the element at that index.
      return nums[index];
    }

    if (index < end) {
      // If the current index is less than the end index, then the maximum amount of money that can be robbed is 0.
      return 0;
    }

    if (dp[index] != -1) {
      // If the dp array already contains the maximum amount of money that can be robbed for the current index, then
      // return the value from the dp array.
      return dp[index];
    }

    // The maximum amount of money that can be robbed from the array starting from the index `index` and ending at the index `end`
    // is the maximum of the following two values:
    //   * The element at the current index, plus the maximum amount of money that can be robbed from the array starting from the index two positions before.
    //   * The maximum amount of money that can be robbed from the array starting from the index one position before.

    int pick = nums[index] + maxRob(nums, end, index - 2, dp);
    int notPick = maxRob(nums, end, index - 1, dp);

    dp[index] = max(pick, notPick);
    // Store the maximum amount of money that can be robbed from the array
    // in the dp array.

    return dp[index];
  }

  int rob(vector<int>& nums) {
    // This function takes the array of numbers as input.

    vector<int> dp1(nums.size() + 1, -1);
    vector<int> dp2(nums.size() + 1, -1);
    int len = nums.size();
    if (len == 1) {
      // If the array only has one element, then the maximum amount of money that can be robbed is simply the element itself.
      return nums[0];
    }

    // Since we are choosing the 0th index, so we are not including the last element.
    int choosing0thIndex = maxRob(nums, 0, len - 2, dp1);
    // Since we are not choosing the 0th index, so we are including the last element.
    int notChoosing0thIndex = maxRob(nums, 1, len - 1, dp2);
    // Return the maximum of the two amounts of money that can be robbed.
    return max(choosing0thIndex, notChoosing0thIndex);
  }
};
