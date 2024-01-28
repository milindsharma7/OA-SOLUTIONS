// if sorting not allowed then implement merge sort

#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n,c;cin>>n>>c;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int l = 1, r = arr[n-1];
    int ans = -1;
    while(l <= r){
        int mid = (l + r) / 2;
        int cnt = 1;int prev = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i] - prev >= mid){
                prev = arr[i];
                cnt++;
            }
        }
        if(cnt >= c){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans ;
}

int main(){
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}