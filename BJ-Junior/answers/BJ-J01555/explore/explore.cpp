#include<bits/stdc++.h>
using namespace std;
char a[5005][5005];
long long n,m,k,x,y,d,lx,ly,ld,lk;
long long T,cnt;
long long dx[]={1,0,-1,0},dy[]={0,1,0,-1},vis[5010][5010];
void dfs(long long k,long long x,long long y,long long d){
    if(k==0){
        return;
    }
    if(lk!=k&&lx==x&&ly==y&&ld==d){
        return;
    }
    vis[y][x]=1;
    if(x+dx[d]>0&&x+dx[d]<=m&&y+dy[d]>0&&y+dy[d]<=n&&a[y+dy[d]][x+dx[d]]!='x'){
        if(vis[y+dy[d]][x+dx[d]]==0){cnt++;}

        dfs(k-1,x+dx[d%4],y+dy[d],d%4);
    }
    else{
        dfs(k-1,x,y,(d+1)%4);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){

        string s;
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>y>>x>>d;
        cnt=1;
        for(long long i=1;i<=n;i++){
                cin>>s;
            for(long long j=1;j<=m;j++){
                a[i][j]=s[j-1];
            }
        }
        lx=x,ly=y,ld=d%4,lk=k;
        dfs(k,x,y,d%4);
        cout<<cnt<<endl;
    }
}
