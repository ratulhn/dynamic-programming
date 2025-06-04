/*

https://cses.fi/problemset/task/1633/

*/

#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

int main() {

    int n; cin>>n;
    int v[] = {1,2,3,4,5,6};

    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=6; j++) {
            if(v[j-1]<=i) dp[i] += dp[i-v[j-1]];
            dp[i]%=M;
        }
    }
    cout << dp[n] << "\n";

    return 0;
}