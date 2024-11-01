#include<bits/stdc++.h>
using namespace std;
char mab[1010][1010];
int v[1010][1010];
int dx[10]={0,1,0,-1},dy[10]={1,0,-1,0};
void dfs(int n,int m,int x,int y,int d,long long k,long long sum){
    if(v[x][y]==0){
        sum++;
        v[x][y]=1;
    }
    if(k==0){
        cout<<sum<<endl;
        return;
    }
    int xx=x+dx[d],yy=y+dy[d];
    if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&mab[xx][yy]!='x'){
        dfs(n,m,xx,yy,d,k-1,sum);
    }else{
        dfs(n,m,x,y,(d+1)%4,k-1,sum);
    }
    return;
}
int main(){

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int t;
    cin>>t;
    while(t--){
        int n,m;
        long long k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mab[i][j];
            }
        }
        dfs(n,m,x,y,d,k,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                v[i][j]=0;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}