#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,a,b,c,ans;
char p[1001][1001];
bool cnt[1001][1001];
int f[4][2]={
0,1,
1,0,
0,-1,
-1,0
};
void dfs(int x,int y,int d,int e){
    if(!cnt[x][y]){
        ++ans;
        cnt[x][y]=1;
    }
    for(int i=d;1;i=(i+1)%4){
        if(e==k) return;
        int xx,yy;
        xx=x+f[i][0],yy=y+f[i][1];
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&p[xx][yy]=='.'){
            ++e;
            dfs(xx,yy,i,e);
            return;
        }
        ++e;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        memset(cnt,0,sizeof(cnt));
        cin>>n>>m>>k;
        cin>>a>>b>>c;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cin>>p[i][j];
            }
        }
        dfs(a,b,c,0);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
