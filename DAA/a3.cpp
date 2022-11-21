#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// Recursive method to calc knapsack
int rec(int wt[], int value[], vector<vector<int>> &dp, int w, int n) {
    if (w==0 || n==0) return 0;

    if (dp[w][n] != -1) return dp[w][n];

    int res;

    // Return answer without considering curr weight
    if (wt[n] > w) res = rec(wt, value, dp, w, n-1);
    else res = max(rec(wt, value, dp, w, n-1), value[n]+rec(wt, value, dp, w-wt[n], n-1));

    return dp[w][n] = res;

}

// Iterative method to calc knapsack
int iter(int wt[], int value[], int w, int n) {
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=w; j++) {
            if (wt[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], value[i-1]+dp[i-1][j-wt[i-1]]);
            }
        }
    }

    return dp[n][w];

}

int main() {

    int n, w;
    cin >> n >> w;

    int value[n], wt[n];

    for (int i=0; i<n; i++) {
        cin >> wt[i];
    }

    for (int i=0; i<n; i++) {
        cin >> value[i];
    }

    vector<vector<int>> dp(w+1, vector<int>(n+1, -1));
    cout << rec(wt, value, dp, w, n);
    cout << "\n" << iter(wt, value, w, n);
    return 0;

    return 0;
}

// Sample Output:
// 4 40
// 30 10 40 20
// 10 20 30 40

// 60
// 60