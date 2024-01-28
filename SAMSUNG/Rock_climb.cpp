#include <iostream>
using namespace std;

int arr[50][50];
int vis[50][50];
int dp[50][50][50];

bool check(int i,int j,int n,int m){
    return (i >= 0 && j >= 0 && i < n && j < m);
}

int dfs(int i,int j,int diff,int n,int m){
    if(arr[i][j] == 3){
        return diff;
    }
    if(dp[i][j][diff] != -1){
        return dp[i][j][diff];
    }
    vis[i][j] = 1;
    int ans = 1e9;
    // left
    if(check(i,j-1,n,m) && !vis[i][j-1] && arr[i][j-1] > 0){
        ans = min(ans , dfs(i,j-1,diff,n,m));
    }
    // right
    if(check(i,j+1,n,m) && !vis[i][j+1] && arr[i][j+1] > 0){
        ans = min(ans , dfs(i,j+1,diff,n,m));
    }
    // up
    int cnt = 0,curr = i-1;
    while(check(curr,j,n,m)){
        cnt++;
        if(!vis[curr][j] && arr[curr][j] > 0){
            ans = min(ans , dfs(curr,j,max(diff,cnt),n,m));
        }
        curr--;
    }
    // down
    cnt = 0,curr = i+1;
    while(check(curr,j,n,m)){
        cnt++;
        if(!vis[curr][j] && arr[curr][j] > 0){
            ans = min(ans , dfs(curr,j,max(diff,cnt),n,m));
        }
        curr++;
    }
    vis[i][j] = 0; 
    return dp[i][j][diff] = ans;
}

void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j] = 0;
            vis[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<max(n,m);k++){
                dp[i][j][k] = -1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout << dfs(n-1,0,0,n,m);
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
// 15 15
// 1 0 1 1 0 1 1 0 1 0 1 0 1 1 0
// 0 1 1 0 1 0 1 0 1 0 1 0 0 1 1
// 1 1 1 0 3 1 0 0 0 1 1 0 1 1 1 
// 0 1 1 0 1 0 1 0 1 0 1 1 0 0 1
// 1 0 1 1 0 1 1 0 1 0 1 0 1 1 0
// 0 1 1 0 1 0 1 0 1 0 1 0 0 1 1
// 1 1 1 0 0 1 0 1 0 1 1 0 1 1 1 
// 0 1 1 0 1 0 1 0 1 0 1 1 0 0 1
// 1 0 1 1 0 1 1 0 1 0 1 0 1 1 0
// 0 1 1 0 1 0 1 0 1 0 1 0 0 1 1
// 1 1 1 0 0 1 0 0 0 1 1 0 1 1 1
// 0 1 1 0 1 0 1 0 1 0 1 1 0 0 1
// 0 1 1 0 1 0 1 0 1 0 1 0 0 1 1
// 1 1 1 0 0 1 0 0 0 1 1 0 1 1 1 
// 1 1 0 1 1 0 1 0 1 0 1 1 0 0 1
