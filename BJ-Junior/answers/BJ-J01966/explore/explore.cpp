#include<bits/stdc++.h>
using namespace std;
int ans = 1;
int t,n,m,k;
int xs,ys,ds;
char a[1005][1005];
int isbeen[1005][1005];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool check(int x,int y){
    if(x>n || y > m || x < 1 || y < 1) return false;
    if(a[x][y] == 'x') return false;
    return true;
}
void dfs(int x,int y,int d,int num){
    if(num == 0) return;
    int xn = x+dx[d];
    int yn = y+dy[d];
    if(!check(xn,yn)){
        int dn = (d+1) % 4;
        num--;
        dfs(x,y,dn,num);
    }else{
        num--;
        if(!isbeen[xn][yn] && xn+yn != 2){
            ans++;
            isbeen[xn][yn] = 1;
        }
        dfs(xn,yn,d,num);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t--){
        memset(isbeen,0,sizeof(isbeen));
        ans = 1;
        cin >> n >> m >> k;
        cin >> xs >> ys >> ds;
        for(int i = 1; i<= n; i++){
            for(int j = 1; j<= m; j++){
                cin >> a[i][j];
            }
        }
        dfs(xs,ys,ds,k);
        cout << ans <<endl;
    }
    return 0;
}