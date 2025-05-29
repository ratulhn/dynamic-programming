#include <bits/stdc++.h>
using namespace std;




int main() {

    int n; cin>>n;
    vector<int>length(n),price(n);
    iota(length.begin(),length.end(),1);
    for(int i=0; i<n; i++) cin>>price[i];

    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(length[i-1]<=j) dp[i][j]=max(dp[i][j-length[i-1]]+price[i-1],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }

    cout << dp[n][n] << "\n";

    return 0;
}