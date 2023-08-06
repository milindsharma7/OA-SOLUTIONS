#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n;cin>>n;
    vector <ll> a(n+1);
    vector <ll> b(n+1);
    vector <ll> h(n+1,0);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>b[i];
    }
    vector <vector <ll>> g(n+1);
    for(ll i=0;i<n-1;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    function <void(ll,ll)> dfs = [&](ll node,ll pp){
        ll totalFruitPassing = 0,maxTimeTaken = 0;
        bool leaf = true;
        for(auto i:g[node]){
            if(i != pp){
                dfs(i,node);
                h[node] = max(h[node],h[i]+1LL);
                totalFruitPassing += a[i] - h[i];
                maxTimeTaken = max(maxTimeTaken,a[i]);
                leaf = false;
            }
        }
        if(!leaf){
            a[node] = maxTimeTaken + min(b[node] , totalFruitPassing - (maxTimeTaken - h[node]));
        }
    };
    dfs(1,1);
    cout << a[1] ;
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