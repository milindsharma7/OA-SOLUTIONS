#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    map <ll,ll> mask;
    vector <vector <ll>> primeFactors(31);
    vector <bool> bad(31);
    for(ll i=2;i<=30;i++){
        if(primeFactors[i].size() > 0){
            continue;
        }
        for(ll j=i;j<=30;j+=i){
            primeFactors[j].push_back(i);
        }
    }
    ll cnt = 0;
    for(ll i=2;i<=30;i++){
        bool ok = true;
        for(ll j=2;j<=i;j++){
            if(i % (j*j) == 0){
                ok = false;
            }
        }
        bad[i] = !ok;
        if(ok == true && primeFactors[i].size() == 1){
            mask[i] = cnt++;
        }
    }
    ll n;cin>>n;
    vector <ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    ll mod = 1e9+7;
    vector <vector <ll>> dp(n+1,vector <ll> ((1LL<<cnt)+1,-1));
    function <ll(ll,ll)> recur = [&](ll idx,ll currMask){
        if(idx == n+1){
            if(!currMask){
                return 0LL;
            }
            return 1LL;
        }
        if(dp[idx][currMask] != -1){
            return dp[idx][currMask];
        }
        ll ans = 0;
        if(bad[v[idx-1]] == true){
            ans += recur(idx+1,currMask);
            ans %= mod;
        }
        else{
            bool ok = true;
            ll newMask = currMask;
            for(auto i:primeFactors[v[idx-1]]){
                if(currMask & (1LL<<mask[i])){
                    ok = false;
                }
                else newMask |= (1LL<<mask[i]);
            }
            if(ok){
                ans += recur(idx+1,newMask);
                ans %= mod;
            }
            ans += recur(idx+1,currMask);
            ans %= mod;
        }
        return dp[idx][currMask] = ans;
    };
    cout << recur(1,0);
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