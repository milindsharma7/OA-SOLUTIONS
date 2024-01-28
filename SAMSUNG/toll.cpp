#include <iostream>
using namespace std;

int n;
int ans;

struct tolls{
    int men;
    int cost;
}toll[100];

void solve(int cur_pos, int bt3, int bt2, int bt1, int cost){
    //optimization
    if(cost>ans) return;
    
    //total men available tofight
    int total_men = bt1 + bt2 + bt3;
    //base case when covered all the toll booths
    if(cur_pos==n){
        ans=min(ans,cost);
        return;
    }

    //pay the toll
    solve(cur_pos + 1, bt3, bt2, bt1, cost + toll[cur_pos].cost);
    // pay double to hire all the man
    solve(cur_pos + 1, bt3 + toll[cur_pos].men, bt2, bt1, cost + 2*toll[cur_pos].cost);

    if(total_men > toll[cur_pos].men){
        if(toll[cur_pos].men > bt1 + bt2)
            bt3 = total_men - toll[cur_pos].men;

        if(toll[cur_pos].men > bt1) 
            bt2 = toll[cur_pos].men >=bt1 + bt2 ? 0 : bt2 - toll[cur_pos].men + bt1;
        
        solve(cur_pos + 1, 0, bt3, bt2, cost);
    }
    
}

int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>n;     //no of tolls

        for(int i=0; i<n; i++)
            cin>>toll[i].men>>toll[i].cost;

        ans=99999;
        solve(0,0,0,0,0);

        cout<<ans<<endl;
    }
    return 0;
}
// 1
// 7 
// 10 100
// 70 5
// 80 15
// 20 60
// 50 90
// 30 80
// 10 10
// 150