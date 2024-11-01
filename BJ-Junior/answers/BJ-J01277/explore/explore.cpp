#include<bits/stdc++.h>
using namespace std;
const int nx[]={0,1,0,-1};
const int ny[]={1,0,-1,0};
int n,m,k;
char maps[1005][1005];
bool vis[1005][1005];
int movex(int x,int y,int d){
    if(d==0) return 0;
    else if(d==1) return 1;
    else if(d==2) return 2;
    else return 3;
}
bool check(int x,int y,int d){
    int t=movex(x,y,d);
    x=x+nx[t];
    y=y+ny[t];
    if(maps[x][y]=='.')return true;
    else return false;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(maps,'0',sizeof(maps));
        memset(vis,false,sizeof(vis));
        cin>>n>>m>>k;
        int x,y,d,ans=1;
        cin>>x>>y>>d;
        vis[x][y]=1;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>maps[i][j];
        while(k--){
            if(check(x,y,d)){
                int t=movex(x,y,d);
                x=x+nx[t];
                y=y+ny[t];
                if(!vis[x][y]){
                    ans++;
                    vis[x][y]=1;
                }
            }else d=(d+1)%4;
        }cout<<ans<<endl;
    }
    return 0;
}

