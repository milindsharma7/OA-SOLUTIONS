#include <iostream>
using namespace std;

int arr[50][5]{};
int dp[50][50][50];

int dfs(int row,int col,int bomb,int used){
    if(row < 0){
        return 0;
    }
    if(dp[row][col][bomb] != -1){
        return dp[row][col][bomb];
    }
    int ans = 0;
    // cout << row << " " << col << "\n" ;
    if(arr[row][col] != 2){
        if(col - 1 >= 0){
            ans = max(ans , arr[row][col] + dfs(row-1,col-1,bomb,used));
        }
        if(col + 1 < 5){
            ans = max(ans , arr[row][col] + dfs(row-1,col+1,bomb,used));
        }
        ans = max(ans , arr[row][col] + dfs(row-1,col,bomb,used));
    }
    else{
        if(used == 1 && bomb - row + 1 <= 5){
            if(col - 1 >= 0){
                ans = max(ans , dfs(row-1,col-1,bomb,used));
            }
            if(col + 1 < 5){
                ans = max(ans , dfs(row-1,col+1,bomb,used));
            }
            ans = max(ans , dfs(row-1,col,bomb,used));
        }
        else if(used == 0){
            if(col - 1 >= 0){
                ans = max(ans , dfs(row-1,col-1,row,1));
            }
            if(col + 1 < 5){
                ans = max(ans , dfs(row-1,col+1,row,1));
            }
            ans = max(ans , dfs(row-1,col,row,1));
        }
    }
    return dp[row][col][bomb] = ans;
}

void solve(int tt){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<5;i++){
        arr[n][i] = 0;
    }
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            for(int k=0;k<50;k++){
                dp[i][j][k] = -1;
            }
        }
    }
    cout << "#" << tt << " " << dfs(n,2,0,0) << "\n";
}

int main(){
    int t = 1;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}