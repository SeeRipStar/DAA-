#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);
    cout << "Enter the values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    int W;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    int max_value = knapsack(W, wt, val, n);
    cout << "Maximum value that can be obtained: " << max_value << endl;

    return 0;
}
