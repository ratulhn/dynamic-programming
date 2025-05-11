
/*
********************************
********************************

NAME: MD. RATUL HOSSAIN
ID: 12308014
CodeForces: https://codeforces.com/profile/Phantom_R

********************************
********************************
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, wt;
    cin >> n >> wt;
    vector<int> val(n), w(n);
    for (int i = 0; i < n; i++) cin >> val[i];
    for (int i = 0; i < n; i++) cin >> w[i];

    vector<vector<int>> dp(n + 1, vector<int>(wt + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= wt; j++) {
            if (w[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - w[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][wt] << "\n";

    return 0;
}
