#include <iostream>
using namespace std;

int adj[50][50]{};
int col[50]{};
int parent[50]{};
int cycle = 0;
int sum = 1e9;
int ans[50]{};

void dfs(int node,int prev,int n){
    if(col[node] == 2){
        return;
    }
    else if(col[node] == 1){
        int curr = prev;
        int temp_sum = 0;
        int sz = 0;
        while(curr != node){
            temp_sum += curr;
            curr = parent[curr];
            sz++;
        }
        temp_sum += curr;
        // cout << temp_sum << "\n";
        sz++;
        if(temp_sum < sum){
            sum = temp_sum;
            cycle = sz;
            /////////////////
            int tmp = 0;
            curr = prev;
            while(curr != node){
                ans[tmp++] = curr;
                curr = parent[curr];
            }
            ans[tmp++] = curr;
            /////////////////
        } 
        return;
    }
    col[node] = 1;
    parent[node] = prev;
    for(int i=1;i<=n;i++){
        if(adj[node][i] > 0){
            dfs(i,node,n);
        }
    }
    col[node] = 2;
}

void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u][v] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<50;j++){
            col[j] = 0;
            parent[j] = 0;
        }
        dfs(i,i,n);
    }
   for (int i = 0; i < cycle - 1; i++) {
        for (int j = 0; j < cycle - i - 1; j++) {
            if (ans[j] > ans[j + 1]) {
                swap(ans[j], ans[j + 1]);
            }
        }
    }
    for(int i=0;i<cycle;i++){
        cout << ans[i] << " " ;
    }
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}