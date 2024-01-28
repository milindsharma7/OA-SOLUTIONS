#include <iostream>
using namespace std;

void solve(){
    int k;cin>>k;
    string s;cin>>s;
    int n = s.size();
    int level = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '('){
            level++;
        }
        else if(s[i] == ')'){
            level--;
        }
        else if(level == k+1){
            int num = s[i] - '0';
            int idx = i+1;
            while(idx < n && s[idx] >= '0' && s[idx] <= '9'){
                num *= 10;
                num += s[idx] - '0';
                idx++;
            }
            i = idx-1;
            ans += num;
        }
    }
    cout << ans ;
}

int main(){
    int t = 1;
    // cin>>t
    while(t--){
        solve();
    }
    return 0;
}