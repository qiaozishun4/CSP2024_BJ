#include<bits/stdc++.h>
using namespace std;
int T,dx[5]={0,1,0,-1},dy[5]={1,0,-1,0},n,m,k,sum,sx,sy,f;
bool mp[1001][1001],vis[1001][1001];
char aa;
void dfs(int x,int y,int f,int step1){
int xx=x+dx[f],yy=y+dy[f];
if(step1==k){
    return ;
}else if(xx<1||xx>n||yy<1||yy>m||mp[xx][yy]==false){
    step1++;
    dfs(x,y,((f+1)%4),step1);
}else{
vis[xx][yy]=1;
step1++;
dfs(xx,yy,f,step1);
}
}
int main(){
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
cin>>T;
while(T--){
        memset(mp,1,sizeof mp);
        memset(vis,0,sizeof vis);
    sum=0;
    cin>>n>>m>>k>>sx>>sy>>f;
    vis[sx][sy]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>aa;
                if(aa=='x'){
                    mp[i][j]=false;
                }else if(aa=='.'){
                    mp[i][j]=true;
                }
            }
        }
        dfs(sx,sy,f,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum+=vis[i][j];
            }
        }
            cout<<sum<<endl;
        
}
return 0;
}
