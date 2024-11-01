#include<bits/stdc++.h>
using namespace std;
const int dy[4]={1,0,-1,0};
const int dx[4]={0,1,0,-1};
char a[1002][1002],n,k,m,t;
int dfs(int x,int y,int di,int step){
    if(step==k){
        return cnt;
    }
    int cnt=0;
    if(x<=1||x>=n||y<=1||y>=m||a[x+dx[di]][y+dy[di]]=='#'){
        dfs(x,y,(di+1)%4,step+1);
    }
    else{
        dfs(x+dx[di],y+dy[di],di,step+1);
        cnt++;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int i=1;i<=m;i++){
                cin>>a[i][m];
            }
        }
        cout<<dfs(x0,y0,d,k)<<"\n";
    }
    return 0;
}
