#include <iostream>
using namespace std;

int dp[11][1024];

struct node{
    int first;
    int second;
};

int recur(int mask,int prev,int sx,int sy,int n,node arr[]){
    if(mask == ((1<<n)-1)){
        return abs(sx-arr[prev].first) + abs(sy-arr[prev].second);
    }
    if(dp[prev][mask] != -1){
        return dp[prev][mask];
    }
    int ans = 1e9;
    for(int i=0;i<n;i++){
        if(!((1<<i) & mask)){
            ans = min(ans , abs(arr[prev].first-arr[i].first) + abs(arr[prev].second-arr[i].second) + recur(mask|(1<<i),i,sx,sy,n,arr));
        }
    }
    return dp[prev][mask] = ans;
}

void solve(int tt){
    int n;cin>>n;
    int sx,sy,dx,dy;
    cin>>sx>>sy>>dx>>dy;
    node arr[n+1];
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    arr[n].first = dx;
    arr[n].second = dy;
    for(int i=0;i<=n;i++){
        for(int j=0;j<(1<<n);j++){
            dp[i][j] = -1;
        }
    }
    cout << "# " << tt << " " << recur(0,n,sx,sy,n,arr) << "\n" ;
}

int main(){
    int t = 10;
    // cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}