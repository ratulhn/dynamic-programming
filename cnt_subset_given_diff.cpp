#include <bits/stdc++.h>
using namespace std;



int check(vector<int>&v,int k) {

    int n=v.size();
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<=n; i++) dp[i][0]=1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(v[i-1]<=j) dp[i][j] = dp[i-1][j] + dp[i-1][j-v[i-1]];
            else dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][k];

}



int main() {


    int n,diff; cin>>n>>diff;
    vector<int>v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    int k = accumulate(v.begin(),v.end(),0);

    cout << check(v,(k+diff)/2) << "\n";
    

    

    return 0;
}