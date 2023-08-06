#include <bits/stdc++.h>
using namespace std;
using ll = long long int;


class Solution {
public:
    bool isScramble(string s1, string s2) {
        unordered_map <string,bool> dp;
        function <bool(string,string)> dfs = [&](string a,string b){
            if(a.size() != b.size()){
                return false;
            }
            if(a == b){
                return true;
            }
            if(a.size() == 1){
                return false;
            }
            string key = a + " " + b;
            if(dp.count(key)){
                return dp[key];
            }
            bool ok = false;
            int n = a.size();
            for(int i=1;i<n;i++){
                if(
                    (
                        dfs(a.substr(0,i),b.substr(0,i)) && dfs(a.substr(i),b.substr(i))
                    ) 
                    || 
                    (
                        dfs(a.substr(0,i),b.substr(n-i)) && dfs(a.substr(i),b.substr(0,n-i))
                    )
                ){
                    ok = true;
                    break;
                }
            }
            return dp[key] = ok;
        };
        return dfs(s1,s2);
    }
};

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}