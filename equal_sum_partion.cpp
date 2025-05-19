#include <bits/stdc++.h>
using namespace std;



void check(vector<int>&v,int k) {

    int n=v.size();
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<=n; i++) dp[i][0]=1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(v[i-1]<=j) dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
            else dp[i][j] = dp[i-1][j];
        }
    }

    if(dp[n][k]) cout << "True\n";
    else cout << "False\n";

}




int main() {


    int n; cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    int sum = accumulate(v.begin(),v.end(),0);

    if(sum%2==0) check(v,sum/2);
    else cout << "False\n";

    

    return 0;
}