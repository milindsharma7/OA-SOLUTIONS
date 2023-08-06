#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n,m;cin>>n>>m;
    vector <ll> a(n-1),b(m-1);
    for(ll i=0;i<n-1;i++){
        cin>>a[i];
    }
    for(ll i=0;i<m-1;i++){
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll itr1 = 0,itr2 = 0;
    ll mod = 1e9+7;
    ll ans = 0;
    while(itr1 < n-1 && itr2 < m-1){
        if(a[itr1] <= b[itr2]){
            ans += (m-itr2)  * a[itr1++];
            ans %= mod;
        }
        else{
            ans += (n-itr1) * b[itr2++];
            ans %= mod;
        }
    }
    while(itr1 < n-1){
        ans += (m-itr2)  * a[itr1++];
        ans %= mod;
    }
    while(itr2 < m-1){
        ans += (n-itr1) * b[itr2++];
        ans %= mod;
    }
    cout << ans ;
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