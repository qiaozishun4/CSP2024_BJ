#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
char a[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int cnt = 1;
bool vis[N][N];
bool check(int l, int r, int x, int y){
    if(x < 1 || x > l || y < 1 || y > r) return false;
    return true;
}
void dfs(int l, int r, int x, int y, int d, int i){
    if(i == 0) return;
    vis[x][y] = true;
    int xx = dx[d]+x, yy = dy[d]+y;
    if(a[xx][yy] == 'x' || !check(l, r, xx, yy)) d = (d+1)%4;
    else{
        if(!vis[xx][yy]) cnt++;
        x = xx;
        y = yy;
    }
    dfs(l, r, x, y, d, i-1);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y, k;
        cin >> x >> y >> k;
        int l, r, d;
        cin >> l >> r >> d;
        for(int j = 1; j <= x; j++){
            for(int s = 1; s <= y; s++){
                cin >> a[j][s];
            }
        }
        dfs(x, y, l, r, d, k);
        cout << cnt << endl;
    }
    return 0;
}
