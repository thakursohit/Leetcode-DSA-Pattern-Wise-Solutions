📘 0/1 Knapsack (DP – Tabulation) Notes
🔹 Problem Statement

Given:

val[i] → value of item i
wt[i] → weight of item i
W → maximum capacity

👉 Find maximum total value such that total weight ≤ W
👉 Each item can be used only once (0/1 constraint)

🔹 DP State Definition
dp[i][w] = maximum value using first i items with capacity w
i → number of items considered
w → current capacity
🔹 Base Case
dp[0][w] = 0   // no items → no value
dp[i][0] = 0   // zero capacity → no value
🔹 Transition (Core Logic)

For every item i:

1. Skip item

dp[i][w] = dp[i-1][w];

2. Pick item (if it fits)

if (wt[i-1] <= w)
    dp[i][w] = val[i-1] + dp[i-1][w - wt[i-1]];

3. Take maximum

dp[i][w] = max(skip, pick);
🔹 Final Answer
return dp[n][W];
🔹 Time & Space Complexity
Type	Complexity
Time	O(n × W)
Space	O(n × W)
🔹 Key Observations (Very Important)
i-1 is used because arrays are 0-based
We refer to dp[i-1] → ensures item is used only once
This is what makes it 0/1 Knapsack (not unbounded)
🔹 Common Mistakes

❌ Iterating forward in 1D optimization
❌ Confusing with Unbounded Knapsack
❌ Using wrong indices (i instead of i-1)

🔹 Space Optimization (1D DP)
int knapsack(int W, vector<int>& val, vector<int>& wt) {
    int n = wt.size();
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}

👉 Why backward loop?

To avoid reusing same item multiple times
🔹 Pattern Recognition (Interview)

Use this approach when:

Items are discrete (not divisible)
Choice = pick or skip
Optimization problem (max/min)
🔹 Related Problems
Subset Sum
Equal Partition
Target Sum
Unbounded Knapsack (variation)
🔹 One-Line Intuition

👉 “For every item, decide: include it or exclude it, and take the best outcome.”