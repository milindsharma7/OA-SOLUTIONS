#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int solution(const vector<int> &a) {
    vector<int> count(128); // -> stores popcount of every number
    for (int i = 1; i < 128; ++i) {
        count[i] = count[i & (i - 1)] + 1;
    }
    vector<vector<int>> dp(2, vector<int>(128, INT_MAX));
    // dp[.][x] means the smallest value of the last element of the subsequence
    // when the xor of all the values == x.
    int last = 0;
    for (int x : a) {
        const int now = last ^ 1;
        dp[now] = dp[last]; // basically space optimization ndp , dp method
        
        // Only take value x as a subsequence of length 1.
        dp[now][x] = min(x, dp[last][x]);
        for (int i = 0; i < 128; ++i) {
            if (dp[last][i] < x && count[i] <= count[x]) {
                const int s = i ^ x;
                dp[now][s] = min(dp[now][s], x);
            }
        } 
        last ^= 1;
    }
    int r = 0;
    for (int x : dp[last]) {
        r += x < INT_MAX;
    }
    return r;
}

void solve(){
    cout << solution({1,2,3,4});
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