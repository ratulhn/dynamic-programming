#include <bits/stdc++.h>
using namespace std;


int main() {

    string a,b; cin>>a>>b;
    int n=a.size(),m=b.size();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));

    int res=0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(a[i-1]==b[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
                res =  max(dp[i][j],res);
            } else dp[i][j]=0;
        }
    }

    cout << res << "\n";

    return 0;
}