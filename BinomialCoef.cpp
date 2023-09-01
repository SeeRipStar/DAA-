#include <iostream>
#include <vector>

using namespace std;

int binomialCoefficient(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k && j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;
    cout << "Enter the values of n and k: ";
    cin >> n >> k;

    if (k < 0 || k > n) {
        cout << "Invalid input. k must be between 0 and n." << endl;
    } else {
        int result = binomialCoefficient(n, k);
        cout << "C(" << n << ", " << k << ") = " << result << endl;
    }

    return 0;
}
