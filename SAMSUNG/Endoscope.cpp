#include <iostream>
using namespace std;

struct node{
    int x;
    int y;
    int level;
};

class queue{
    private:
        node *arr;
        int n;
        int front;
        int back;
        int sz = 0;
    public:
        queue(int n){
            this->n = n;
            arr = new node[n];
            front = 0;
            back = 0;
        }
        void push(int x, int y, int level){
            arr[back].x = x;
            arr[back].y = y;
            arr[back].level = level;
            back++;
            sz++;
            back %= n;
        }
        void pop(){
            arr[front].x = 0;
            arr[front].y = 0;
            arr[front].level = 0;
            front++;
            sz--;
            front %= n;
        }
        node top(){
            return arr[front];
        }
        bool empty(){
            return (sz == 0);
        }
        ~queue(){
            delete[] arr;
        }
};

bool valid(int x, int y, int n, int m){
    return (x < n && y < m && x >= 0 && y >= 0);
}

bool left(int num){
    return (num == 1 || num  == 3 || num == 6 || num == 7);
}

bool right(int num){
    return (num == 1 || num == 3 || num == 4 || num == 5);
}

bool up(int num){
    return (num == 1 || num == 2 || num == 4 || num == 7);
}

bool down(int num){
    return (num == 1 || num == 2 || num == 5 || num == 6);
}

void solve(){
    int n,m,x1,y1,l;cin>>n>>m>>x1>>y1>>l;
    queue q(n*m);
    int vis[n][m];
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            vis[i][j] = 0;
        }
    }
    q.push(x1, y1, l-1);
    vis[x1][y1] = 1;
    int ans = 0;
    while(!q.empty()){
        node f = q.top();
        q.pop();
        int x = f.x; 
        int y = f.y; 
        if(arr[x][y] == 0){
            continue;
        }
        ans++;
        // cout << x << " " << y << "\n" ;
        int level = f.level;
        if(level == 0){
            continue;
        }
        if(valid(x-1,y,n,m) && !vis[x-1][y] && up(arr[x][y]) && down(arr[x-1][y])){
            vis[x-1][y] = 1;
            q.push(x-1,y,level-1);
        }
        if(valid(x+1,y,n,m) && !vis[x+1][y] && down(arr[x][y]) && up(arr[x+1][y])){
            vis[x+1][y] = 1;
            q.push(x+1,y,level-1);
        }
        if(valid(x,y-1,n,m) && !vis[x][y-1] && left(arr[x][y]) && right(arr[x][y-1])){
            vis[x][y-1] = 1;
            q.push(x,y-1,level-1);
        }
        if(valid(x,y+1,n,m) && !vis[x][y+1] && right(arr[x][y]) && left(arr[x][y+1])){
            vis[x][y+1] = 1;
            q.push(x,y+1,level-1);
        }
    }
    cout << ans << "\n" ;
}

int main(){
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}