/*  https://www.codingninjas.com/studio/problems/frog-jump_3621012?leftPanelTab=1  */
#include <iostream>

using namespace std;

int min_energy(int index, vector<int>& heights, vector<int>& dp) {
  // This function calculates the minimum amount of energy
  // needed to reach the current index.

  if (index == 0) {
    // If the current index is 0, then the minimum amount
    // of energy needed to reach it is 0.
    return 0;
  }

  if (dp[index] != -1) {
    // If the dp array already contains the minimum amount
    // of energy needed to reach the current index, then
    // return the value from the dp array.
    return dp[index];
  }

  int left = abs(heights[index] - heights[index - 1]) + min_energy(index - 1, heights, dp);
  // The minimum amount of energy needed to reach the current index
  // is the minimum of the following two values:
  //   * The minimum amount of energy needed to reach the previous index,
  //     plus the energy needed to jump to the current index.
  //   * The minimum amount of energy needed to reach the index two positions before,
  //     plus the energy needed to jump two positions to the current index.

  int right = INT_MAX;
  if (index > 1) {
    right = abs(heights[index] - heights[index - 2]) + min_energy(index - 2, heights, dp);
  }

  dp[index] = min(left, right);
  // Store the minimum amount of energy needed to reach the current index
  // in the dp array.

  return dp[index];
}

int frog_jump(int n, vector<int>& heights) {
  // This function takes the number of numbers on the number line
  // and the heights array as input.

  vector<int> dp(n, 0);
  // Initialize the dp array to 0.

  dp[0] = 0;
  // Loop through the dp array and calculate the minimum amount
  // of energy needed to reach each index.

  for (int j = 1; j < n; j++) {
    int left = dp[j - 1] + abs(heights[j] - heights[j - 1]);
    int right = INT_MAX;
    if (j > 1) {
      right = dp[j - 2] + abs(heights[j] - heights[j - 2]);
    }

    dp[j] = min(left, right);
  }
  // Return the minimum amount of energy needed to reach the rightmost index.

  return dp[n - 1];
}

int main() {
  vector<int> heights = {1, 3, 1, 4, 2, 3};
  int n = heights.size();
  int result = frog_jump(n, heights);
  cout << "The minimum amount of energy needed to reach the rightmost index is: " << result << endl;
  return 0;
}
