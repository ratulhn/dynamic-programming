#include <bits/stdc++.h>
using namespace std;




int main() {

    int n,s; cin>>n>>s;
    vector<int>v(n); 
    for(int i=0; i<n; i++) cin>>v[i];
    int dp[n+1][s+1];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<=n; i++) dp[i][0]=1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=s; j++) {
            if(v[i-1]<=j) dp[i][j]=dp[i-1][j] || dp[i-1][j-v[i-1]];
            else dp[i][j]=dp[i-1][j];
        }
    }

    if(dp[n][s]) cout << "YES\n";
    else cout << "NO\n";



    return 0;
}