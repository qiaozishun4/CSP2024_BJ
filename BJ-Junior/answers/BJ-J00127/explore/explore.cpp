#include<bits/stdc++.h>
using namespace std;
string s;
char maze[1001][1001];
bool v[1001][1001];
int k,n,m,T,dis;
struct node{
    int x,y;
}d[4]={{0,1},{1,0},{0,-1},{-1,0}};
int dfs(int x,int y,int i,int cnt){
   // cout<<cnt<<" "<<k<<endl;

    if(!k){
        return cnt;
    }
    int next_x=x+d[i].x;
    int next_y=y+d[i].y;
    //cout<<d[i].y<<endl;
    if(next_x>=1&&next_y>=1&&next_x<=n&&next_y<=m&&maze[next_x][next_y]=='.'){
        k--;
        if(v[next_x][next_y]){
            return dfs(next_x,next_y,i,cnt);
        }
        v[next_x][next_y]=1;
        return dfs(next_x,next_y,i,cnt+1);
    }
    k--;
    return dfs(x,y,(i+1)%4,cnt);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
   // freopen("explore.in","w",stdout);
    int cnt=0;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>m>>k;
        int x,y,o;
        cin>>x>>y>>dis;
        for(int j=1;j<=n;j++){
            cin>>s;
            for(int t=0;t<m;t++){
                maze[j][t+1]=s[t];
            }
        }
        v[x][y]=1;
        cnt=dfs(x,y,dis,1);
        for(int j=1;j<=n;j++){
            for(int t=1;t<=m;t++){
                maze[j][t]=0;
                v[j][t]=0;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
