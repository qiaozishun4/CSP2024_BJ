#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int t, n, m, k;
int a[1010][1010];
int startx, starty, startd;
int fx[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool check(int x, int y){
    return x <= n && y<=m && x>=1 && y>=1 && a[x][y] != 1;
}

void dfsr(){
    int x = startx, y = starty, d = startd;
    a[startx][starty] = 2;
    for(int i=1; i<=k; i++){
        int xx = x + fx[d][0], yy = y + fx[d][1];
        if(check(xx, yy)){
            x = xx, y = yy;
        }
        else{
            d = (d+1)%4;
        }
        a[x][y] = 2;
    }
}

int main(){

    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin>>t;
    while(t--){
        int ans = 0;
        cin>>n>>m>>k;
        cin>>startx>>starty>>startd;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                char temp;
                cin>>temp;
                if(temp=='.') a[i][j] = 0;
                else a[i][j] = 1;
            }
        }
        dfsr();
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i][j] == 2) ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
