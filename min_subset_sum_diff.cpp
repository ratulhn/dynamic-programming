#include <bits/stdc++.h>
using namespace std;




int main() {

    int n,s; cin>>n;
    vector<int>v(n); 
    for(int i=0; i<n; i++) cin>>v[i];
    s=accumulate(v.begin(),v.end(),0);
    int dp[n+1][s+1];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<=n; i++) dp[i][0]=1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=s; j++) {
            if(v[i-1]<=j) dp[i][j]=dp[i-1][j] || dp[i-1][j-v[i-1]];
            else dp[i][j]=dp[i-1][j];
        }
    }

    for(int i=s/2; i>=0; i--) {
        if(dp[n][i]) {
            cout << s-2*i << "\n";
            break;
        }
    }





    return 0;
}