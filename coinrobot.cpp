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
    
    int n,m; cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>v[i][j];
        }
    }
    
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+v[i-1][j-1];
        }
    }

    cout << dp[n][m] << "\n";


    return 0;
}
