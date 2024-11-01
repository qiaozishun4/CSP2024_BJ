#include<bits/stdc++.h>
using namespace std;
int t,v[1001][1001],dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char a[1001][1001];
void cal(){
    memset(v,0,sizeof v);
    int n,m,k,x,y,d,ans=1;
    cin>>n>>m>>k>>x>>y>>d;
    v[x][y]=1;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
    while(k--){
        int nx=x+dx[d],ny=y+dy[d];
        if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x')d=(d+1)%4;
        else{
            if(!v[nx][ny])ans++;
            x=nx,y=ny,v[nx][ny]=1;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)cal();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
