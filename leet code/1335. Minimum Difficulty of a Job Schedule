class Solution {
public:
    int dp[301][11];
    int solve(int id,vector<int>&jd, int n, int d) {
        if(d==1) {
            int mx=jd[id];
            for(int i=id; i<n; i++) mx=max(mx,jd[i]);
            return mx;
        }
        if(dp[id][d]!=-1) return dp[id][d];
        int mx=jd[id];
        int res=INT_MAX;
        for(int i=id; i<=n-d; i++) {
            mx=max(jd[i],mx);
            int cur=mx+solve(i+1,jd,n,d-1);
            res=min(res,cur);
        }
        return dp[id][d]=res;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n= jobDifficulty.size();
        if(d>n) return -1;
        memset(dp,-1,sizeof(dp));
        
        int i=0;
        int res= solve(i,jobDifficulty,n,d);
        return res;
    }
};
