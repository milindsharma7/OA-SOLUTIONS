// k-toggle question without hashmap we can do O(N^3)

#include <iostream>
using namespace std;

int main(){
    int n,m,k1;cin>>n>>m>>k1;
    int mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int tot = 0;int zero = 0;
        for(int j=0;j<n;j++){
            int cnt = 0;
            for(int k=0;k<m;k++){
                if(mat[j][k] == mat[i][k]){
                    cnt++;
                }
            }
            if(cnt == m){
                tot++;
            }
        }
        for(int j=0;j<m;j++){
            if(mat[i][j] == 0){
                zero++;
            }
        }
        if(zero <= k1 && abs(k1 - zero) % 2 == 0){
            ans = max(ans , tot);
        }
    }
    cout << ans ;
    return 0;
}

// 15 15 7
// 1 0 1 1 0 1 1 0 1 0 1 0 1 1 0
// 0 1 1 0 1 0 1 0 1 0 1 0 0 1 1
// 1 1 1 0 0 1 0 0 0 1 1 0 1 1 1 
// 0 1 1 0 1 0 1 0 1 0 1 1 0 0 1
// 1 0 1 1 0 1 1 0 1 0 1 0 1 1 0
// 0 1 1 0 1 0 1 0 1 0 1 0 0 1 1
// 1 1 1 0 0 1 0 0 0 1 1 0 1 1 1 
// 0 1 1 0 1 0 1 0 1 0 1 1 0 0 1
// 1 0 1 1 0 1 1 0 1 0 1 0 1 1 0
// 0 1 1 0 1 0 1 0 1 0 1 0 0 1 1
// 1 1 1 0 0 1 0 0 0 1 1 0 1 1 1
// 0 1 1 0 1 0 1 0 1 0 1 1 0 0 1
// 0 1 1 0 1 0 1 0 1 0 1 0 0 1 1
// 1 1 1 0 0 1 0 0 0 1 1 0 1 1 1 
// 0 1 1 0 1 0 1 0 1 0 1 1 0 0 1

// ans = 4