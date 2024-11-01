#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
char a[maxn][maxn];
bool v[maxn][maxn];
/*
若 d = 0,则令(x, y + 1),
若 d = 1,则令(x + 1, y),
若 d = 2,则令(x, y − 1),
若 d = 3,则令(x − 1, y)。
*/
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void work(){
    int n,m,k,x,y,d,s=0;
    memset(a,0,sizeof(a));

    cin>>n>>m>>k;
    cin>>x>>y>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            v[i][j]=0;
        }
    }
    v[x][y]=1;
    while(k--){
        int tx=x+dx[d];
        int ty=y+dy[d];
        if(a[tx][ty]=='.')
            x=tx,y=ty,v[x][y]=1;
        else d=(d+1)%4;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            s+=v[i][j];
        }
    }
    cout<<s<<'\n';
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;cin>>t;
    while(t--)work();
    return 0;
}
