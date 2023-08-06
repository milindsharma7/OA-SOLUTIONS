#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n,m;cin>>n>>m;
    vector <ll> v(m);
    for(ll i=0;i<m;i++){
        cin>>v[i];
    }
    vector <ll> cnt(64,0);
    bitset <64> bs(n);
    for(ll i=0;i<m;i++){
        ll lg = 0;
        ll num = v[i];
        while(num){
            lg++;
            num /= 2;
        }
        cnt[lg-1]++;
    }
    ll ans = 0;
    for(ll i=0;i<62;i++){
        if(bs[i] > 0 && cnt[i] == 0){
            bool found = false;
            for(ll j=i+1;j<62;j++){
                if(cnt[j] > 0){
                    found = true;
                    ans += j-i;
                    for(ll k=i;k<j;k++){
                        cnt[k]++;
                    }
                    cnt[j]--;
                    break;
                }
            }
            if(found == false){
                std::cout << "-1\n";
                return;
            }
        }
        else{
            cnt[i+1] += (cnt[i] - bs[i]) / 2;
        }
    }
    std::cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}