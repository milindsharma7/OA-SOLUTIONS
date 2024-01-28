#include <iostream>
using namespace std;

int dp[12][2048];
int mat[13][13];

int recur(int mask,int prev,int n){
    if(mask == ((1<<n)-1)){
        return mat[prev][0];
    }
    if(dp[prev][mask] != -1){
        return dp[prev][mask];
    }
    int ans = 1e9;
    for(int i=0;i<n;i++){
        if(!((1<<i) & mask)){
            ans = min(ans , mat[prev][i] + recur(mask|(1<<i),i,n));
        }
    }
    return dp[prev][mask] = ans;
}

void solve(int tt){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<n);j++){
            dp[i][j] = -1;
        }
    }
    cout << recur(1,0,n) << "\n" ;
}

int main(){
    int t = 10;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}