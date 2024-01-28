#include <iostream>
using namespace std;

int recur(int idx,int cnt,bool start,bool tight,int k,int n,int dig,int arr[]){
    int lim = 9;
    int temp = dig;
    int tot = 0;
    while(temp){
        tot++;
        temp /= 10;
    }
    if(idx == tot+1){
        return 1;
    }
    temp = dig;
    for(int i=0;i<tot-idx;i++){
        temp /= 10;
    }
    int d = temp % 10;
    // cout << d << " " << idx << "\n" ;
    if(tight == true){
        lim = d;
    }
    int ans = 0;
    if(start == false){
        for(int i=1;i<=lim;i++){
            if(arr[i] > 0 && cnt < k-1){
                ans += recur(idx+1,cnt+1,true,(i==lim)&&tight,k,n,dig,arr);
            }
            else if(arr[i] == 0){
                ans += recur(idx+1,cnt,true,(i==lim)&&tight,k,n,dig,arr);
            }
        }
        ans += recur(idx+1,cnt,false,false,k,n,dig,arr);
    }
    else{
        for(int i=0;i<=lim;i++){
            if(arr[i] > 0 && cnt < k-1){
                ans += recur(idx+1,cnt+1,true,(i==lim)&&tight,k,n,dig,arr);
            }
            else if(arr[i] == 0){
                ans += recur(idx+1,cnt,true,(i==lim)&&tight,k,n,dig,arr);
            }
        }
    }
    return ans;
}

int main(){
    int a,b,k;
    cin>>a>>b>>k;
    int n;cin>>n;
    int arr[10]{0};
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        arr[t] = 1;
    }
    cout << recur(1,0,false,true,k,n,b,arr) - recur(1,0,false,true,k,n,a-1,arr);
    return 0;
}

// 24 12943 3
// 3
// 1 3 5
// 10997