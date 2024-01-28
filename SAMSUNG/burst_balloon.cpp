#include <iostream>
using namespace std;

int dp[11][11];

int recur(int l,int r,int n,int arr[]){
    if(l > r){
        return 0;
    }
    else if(dp[l][r] != -1){
        return dp[l][r];
    }
    int ans = 0;
    for(int i=l;i<=r;i++){
        int l1 = 1,r1 = 1;
        if(l > 0){
            l1 = arr[l-1];
        }
        if(r < n-1){
            r1 = arr[r+1];
        }
        int tot = 0;
        if(l == 0 && r == n-1){
            tot = arr[i];
        }
        else tot = l1 * r1;
        ans = max(ans , tot + recur(l,i-1,n,arr) + recur(i+1,r,n,arr));
    }
    return dp[l][r] = ans;
}

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    cout << recur(0,n-1,n,arr) << "\n" ;
}

int main(){
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}