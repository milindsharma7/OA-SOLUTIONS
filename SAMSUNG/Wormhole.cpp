#include <iostream>
using namespace std;

void solve(){
    int n;cin>>n;
    int sx,sy,dx,dy;
    cin>>sx>>sy>>dx>>dy;
    int arr[n][5];
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
        }
    }
    // total nodes = source + destination + 2 * n = 2 * n + 2
    // 0 -> source, 1 2 3 ... n -> worm holes entry, n+1 n+2 n+3 ... 2*n -> worm hole exit, 2*n + 1 -> destination
    int dist[2*n+2];
    for(int i=0;i<2*n+2;i++){
        dist[i] = 1e9;
    }
    int adj[2*n+2][2*n+2];
    for(int i=0;i<2*n+2;i++){
        for(int j=0;j<2*n+2;j++){
            adj[i][j] = 1e9;
        }
    }
    for(int i=1;i<=n;i++){
        adj[i][i+n] = arr[i-1][4];
        adj[n+i][i] = arr[i-1][4];
    }
    for(int i=0;i<2*n+2;i++){
        for(int j=0;j<2*n+2;j++){
            if(i == j){
                continue;
            }
            int x1,y1,x2,y2;
            if(i == 0){
                x1 = sx;
                y1 = sy;

            }
            else if(i == 2*n+1){
                x1 = dx;
                y1 = dy;
            }
            else{
                if(i <= n){
                    x1 = arr[i-1][0];
                    y1 = arr[i-1][1];
                }
                else{
                    x1 = arr[i-n-1][2];
                    y1 = arr[i-n-1][3];
                }
            }
            if(j == 0){
                x2 = 0;
                y2 = 0;
            }
            else if(j == 2*n+1){
                x2 = dx;
                y2 = dy;
            }
            else{
                if(j <= n){
                    x2 = arr[j-1][0];
                    y2 = arr[j-1][1];
                }
                else{
                    x2 = arr[j-n-1][2];
                    y2 = arr[j-n-1][3];
                }
            }
            int cost = abs(x1-x2) + abs(y1-y2);
            adj[i][j] = min(cost , adj[i][j]);
        }
    }
    dist[0] = 0;
    for(int i=0;i<2*n+1;i++){
        for(int j=0;j<2*n+2;j++){
            for(int k=0;k<2*n+2;k++){
                if(j == k){
                    continue;
                }
                if(dist[k] > dist[j] + adj[j][k]){
                    dist[k] = dist[j] + adj[j][k];
                }
            }
        }
    }
    // for(int i=0;i<2*n+2;i++){
    //     for(int j=0;j<2*n+2;j++){
    //         cout << adj[i][j] << " " ;
    //     }
    //     cout << "\n" ;
    // }
    cout << dist[2*n+1] << "\n" ;
}

int main(){
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}