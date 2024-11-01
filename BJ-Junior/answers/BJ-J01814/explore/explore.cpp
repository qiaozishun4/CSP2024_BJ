#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10,inf=0x3f3f3f3f;
int t,n,m,k,sx,sy,d;
string s[maxn];
bool vis[maxn][maxn];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool ind(int x,int y){
    return x>=0 && y>=0 && x<n && y<m;
}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k>>sx>>sy>>d; sx--,sy--;
        int x=sx,y=sy;
        vis[sx][sy]=1;
        for(int i=0;i<n;i++) cin>>s[i];
        int ans=1;
        while(k--){
            int xx=x+dx[d],yy=y+dy[d];
            if(ind(xx,yy) && s[xx][yy]=='.'){
                if(vis[xx][yy]!=1) vis[xx][yy]=1,ans++;
                x=xx,y=yy;
            }else d=(d+1)%4;
        }
        cout<<ans<<endl;
    }
    return 0;
}
