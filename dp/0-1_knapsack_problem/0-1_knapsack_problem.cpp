class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
          int n = wt.size();
           vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {  
        for (int w = 0; w <= W; w++) {  

           
            dp[i][w] = dp[i - 1][w];

            if (wt[i - 1] <= w) {
                int valueIfPicked = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                dp[i][w] = max(dp[i][w], valueIfPicked);
            }
        }
    }
    
    return dp[n][W];
        
    }
};