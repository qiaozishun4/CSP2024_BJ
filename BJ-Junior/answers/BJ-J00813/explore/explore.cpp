#include <bits/stdc++.h>
using namespace std;
int di[5] = {0,1,0,-1},dj[5] = {1,0,-1,0},n,m,d,bs,ans,cnt,a[10010],g,cx,cy,b;
string w[1010];
void dfs(int i,int j,int f){
    if(bs = 0){
        for(int o = 1;o <= n; o++){
            for(int v = 1;v <= m;v++){
                if(a[o][y] != 0){
                    cnt++;
                }
            }
        }
        return;
    }
    x = i+di[f];
    y = j + dj[f];
    if(i >= 1 && i <= n && j >= 1 && j <= m && w[x][y] == "."){
        bs = bs-1;
        a[x][y] = 1;
        dfs(x,y);
    }
    else{
        if(f < 3){
            f++;
        }
        else{
            f = 0;
        }
        bs--;
        dfs(i,j,f);
    }
}
int main(){
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
    cin >> b;
    for(int k = 0;k < b;k++){
        cin >> n >> m >> bs >> cx >> cy >> d;
        for(int l = 1;l <= n;l++){
            cin >> w[l];
        }
        dfs(cx,cy,d);
        cout << cnt << endl;
        cnt = 0;

    }
    return 0;
}