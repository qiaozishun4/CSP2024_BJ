#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
int T,cnt,vis[N][N];
int m,n,k,x_0,y_0,d,a[N][N];
string s;
int fx[5]={0,1,0,-1};
int fy[5]={1,0,-1,0};
inline void dfs(int x,int y,int step){
    if(vis[x][y]!=1){
        vis[x][y]=1;
        cnt++;
    }
    if(step>=k)return;
    if(a[x+fx[d]][y+fy[d]]==1){
        if(step+1>k)return;
        dfs(x+fx[d],y+fy[d],step+1);
        return;
    }
    d=(d+1)%4;
    if(a[x+fx[d]][y+fy[d]]==1){
        if(step+2>k)return;
        dfs(x+fx[d],y+fy[d],step+2);
        return;
    }
    d=(d+1)%4;
    if(a[x+fx[d]][y+fy[d]]==1){
        if(step+3>k)return;
        dfs(x+fx[d],y+fy[d],step+3);
        return;
    }
    d=(d+1)%4;
    if(a[x+fx[d]][y+fy[d]]==1){
        if(step+4>k)return;
        dfs(x+fx[d],y+fy[d],step+4);
        return;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        cnt=0;
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k>>x_0>>y_0>>d;
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=1;j<=m;j++){
                switch(s[j-1]){
                    case '.':
                        a[i][j]=1;
                        break;
                }
            }
        }
        dfs(x_0,y_0,0);
        cout<<cnt<<'\n';
    }
    return 0;
}
