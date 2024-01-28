#include <iostream>
using namespace std;

//no of rows and colomns
int n,m;
int a[1000][1000];
bool visited[1000][1000];
int dx[] = {-2,-1,1,2,1,-1};
int dy[] = {0,1,1,0,-1,-1};

bool valid(int x, int y){
    if(x>=0 && x<2*n && y>=0 && y<m)
        return true;
    return false;
}

int non_inverted_Y(int x, int y){
    if(valid(x+2,y) && valid(x-1, y-1) && valid(x-1, y+1))
        return (a[x][y] + a[x+2][y] + a[x-1][y+1] + a[x-1][y-1]);
    return -1;
}

int inverted_Y(int x, int y){
    if(valid(x-2,y) && valid(x+1, y-1) && valid(x+1, y+1))
        return (a[x][y] + a[x-2][y] + a[x+1][y+1] + a[x+1][y-1]);
    return -1;
}

int dfs(int x,int y, int count){
    if(count==0) return 0;

    visited[x][y]=true;
    int ans=0;
    for(int i=0; i<6; i++){
        int m = x + dx[i];
        int n = y + dy[i];

        if(valid(m,n) && visited[m][n]!=true){
            visited[m][n]=true;
            int temp= dfs(m,n,count -1);
            visited[m][n]=false;

            ans=max(temp,ans);
        }
    }
    visited[x][y]=false;
    ans+=a[x][y];
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;

        //taking input in hexagon style
        for(int i = 0; i<(2*n); i+=2){
            int k = i;
            for(int j =0; j<m; j++){
                cin>>a[k][j];
                if(k == (1+i))k = i;
                else
                k = 1+i;
            }
        }

        int ans=-1;
        for(int i=0; i<2*n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j]){
                    int temp1 = dfs(i,j,4);
                    int temp2 = inverted_Y(i,j);
                    int temp3 = non_inverted_Y(i,j);
                    int temp4 = max(temp2,temp3);
                    ans = max (max (temp1, temp4), ans);
                }
            }
        } 
        cout<<ans<<endl;
    }
    return 0;
}

/*
test cases:-
6
3 4
150 450 100 320
120 130 160 110
10 60 200 220
1 4
10 20 30 40
3 5
300 410 150 55 370
120 185 440 190 450
165 70 95 420 50
5 5
356 55 41 453 12
401 506 274 506 379
360 281 421 311 489
425 74 276 371 164
138 528 461 477 470
3 13
197 51 443 274 47 552 160 96 501 102 469 318 308
516 128 506 471 381 418 328 517 380 78 569 58 90
113 238 179 444 541 27 444 62 264 93 245 353 37
11 7
292 182 586 607 259 190 239
511 716 425 367 511 462 714
593 713 231 60 118 442 82
626 577 579 682 136 176 681
240 23 410 193 230 729 109
453 231 287 383 444 578 409
729 401 408 330 213 574 54
684 224 75 62 660 472 227
606 37 473 487 222 185 476
84 477 158 94 141 484 122
616 333 302 626 29 99 674
output:-
1130
100
1500
1936
1982
2690
*/
