#include <bits/stdc++.h>
using namespace std;




int main() {

    int n,sum; cin>>n>>sum;
    vector<int>v(n); 
    for(int i=0; i<n; i++) cin>>v[i];

    int dp[n+1][sum+1];
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=sum; i++) dp[0][i]=INT_MAX-1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            if(v[i-1]<=j) dp[i][j]=min(dp[i-1][j],dp[i][j-v[i-1]]+1);
            else dp[i][j]=dp[i-1][j];
        }
    }
    if(dp[n][sum]==INT_MAX-1) dp[n][sum]=-1;
    cout << dp[n][sum] << "\n";


    

    return 0;
}