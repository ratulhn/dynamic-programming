class Solution {
public:
    bool duplicate(string s1, string s2) {
        vector<int>hsh(26);
        for(auto &c:s1) {
            if(hsh[c-'a']>0) return true;
            hsh[c-'a']++;
        }
        for(auto &c:s2) {
            if(hsh[c-'a']>0) return true;
            hsh[c-'a']++;
        }
        return false;
    }
    map<pair<string,int>,int>mp;
    int solve(int i, vector<string>&v,int n, string tmp) {
        if(i>=n) return tmp.size();
        if(mp.count({tmp,i})) return mp[{tmp,i}];
        int s1=-1e9,s2=-1e9;
        if(duplicate(v[i],tmp)) {
            s2=solve(i+1,v,n,tmp);
        } else {
            s1=solve(i+1,v,n,tmp+v[i]);
            s2=solve(i+1,v,n,tmp);
        }

        return mp[{tmp,i}]= max(s1,s2);
    }


    int maxLength(vector<string>& arr) {
        string tmp="";
        return solve(0,arr,arr.size(),tmp);
    }
};
