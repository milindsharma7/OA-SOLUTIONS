#include <iostream>
using namespace std;
#define inf 1e9
int cap[3],balloon[3];

int recur(int idx1,int idx2,int n){
    if(idx2 == 3){
        return 0;
    }
    else if(idx1 > n){
        return inf;
    }
    else if(idx1 + cap[idx2] > n+1){
        return inf;
    }
    int ans = inf;
    // int cost = cap[idx2] * idx1 + cap[idx2] * (cap[idx2]-1) / 2 - cap[idx2] * balloon[idx2];
    int cost = cap[idx2];int temp = idx1;
    for(int i=0;i<cap[idx2];i++){
        cost += abs(temp - balloon[idx2]);
        temp++;
    }
    ans = min(ans , cost + recur(idx1+cap[idx2],idx2+1,n));
    ans = min(ans , recur(idx1+1,idx2,n));
    return ans;
}
// idx1 - balloon[idx2] + (idx1 + 1) - balloon[idx2] + (idx1+2) - balloon[idx2] + (idx+3) - balloon[idx2]
// cap[idx2] * idx1 + cap[idx2] * (cap[idx2]-1) / 2 - cap[idx2] * balloon[idx2]

void solve(){
    int n;cin>>n;
    for(int i=0;i<3;i++){
        cin>>balloon[i]; 
    }
    for(int i=0;i<3;i++){
        cin>>cap[i];
    }
    cout << recur(1,0,n);
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}