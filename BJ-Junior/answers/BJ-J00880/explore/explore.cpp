#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+10;
int n,m,k,a[MAXN][MAXN],x0,y00,d0,x,y,T,d,cnt;
string s;
bool vis[MAXN][MAXN];
void judge(int &d,int &x,int &y){
    int x2 = x;
    int y2 = y;
    if(d==0)y2++;
    if(d==1)x2++;
    if(d==2)y2--;
    if(d==3)x2--;
    if(x2 <1||x2>n||y2<1||y2>m||a[x][y]==0){
        d = (d+1)%4;
        return;
    }
    x = x2;
    y = y2;
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        cnt=0;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x0,&y00,&d0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j] =0;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=0;j<m;j++){
                if(s[j] == 'x')a[i][j+1] = 0;
                else a[i][j+1] = 1;
            }
        }
        vis[x0][y00] = 1;
        x=x0;y=y00;d=d0;
        for(int i=1;i<=k;i++){
            judge(d,x,y);
            vis[x][y] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j])cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
