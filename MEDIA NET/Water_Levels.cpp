#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

class FenwickTree{
    private:
        vector <ll> Tree;
        vector <ll> Prefix;
    public:
        FenwickTree(vector <ll> &arr){
            ll n = arr.size();
            Tree.resize(n+1,0);
            Prefix.resize(n+1,0);
            for(ll i=1;i<=n;i++){
                Prefix[i] = Prefix[i-1] + arr[i-1]; 
            }
            for(ll i=1;i<=n;i++){
               Tree[i] = Prefix[i] - Prefix[i-(i&-i)];  
            }
        }
        void build(ll idx,ll num){
            ll sum = 0;
            while(idx<Tree.size()){
                Tree[idx] += num;
                idx += (idx&-idx);
            }
        }
        long long int prefix(ll idx){
            ll sum = 0;
            while(idx>0){
                sum += Tree[idx];
                idx -= (idx&-idx);
            }
            return sum;
        }
        long long int query(ll l,ll r){
            return prefix(r) - prefix(l-1);
        }
        void update(ll idx,ll num){
            ll old = query(idx,idx);
            ll delta = num - old;
            build(idx,delta);
        }
};

void solve(){
    ll n,q;cin>>n>>q;
    vector <ll> v(n+1);
    vector <ll> death_time(n+1);
    vector <ll> tree(q+1);
    vector <ll> reverse_death_time(q+1);
    for(ll i=1;i<=n;i++){
        cin>>v[i];
    }
    vector <vector <vector <ll>>> queries(n+1);
    vector <vector <vector <ll>>> queriesEnd(n+1);
    for(ll i=0;i<q;i++){
        ll l,r,k;
        cin>>l>>r>>k;
        queries[l].push_back({i+1,r,k});
        queriesEnd[r].push_back({i+1,l,k});
    }
    FenwickTree Time(tree);
    for(ll i=1;i<=n;i++){
        for(auto j:queries[i]){
            Time.build(j[0],+j[2]);
        }
        ll l = 0,r = q;
        ll time_of_death = -1;
        while(l <= r){
            ll mid = (l+r)/2;
            ll sum = Time.prefix(mid);
            if(sum >= v[i]){
                r = mid-1;
                time_of_death = mid;
            }
            else l = mid+1;
        }
        if(time_of_death != -1){
            death_time[i] = time_of_death;
            reverse_death_time[time_of_death]++;
        }
        for(auto j:queriesEnd[i]){
            Time.build(j[0],-j[2]);
        }
    }
    ll ans = 0;
    for(ll i=1;i<=q;i++){
        if(reverse_death_time[i] > 0){
            ans += reverse_death_time[i];
        }
        cout << ans << " " ;
    }
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