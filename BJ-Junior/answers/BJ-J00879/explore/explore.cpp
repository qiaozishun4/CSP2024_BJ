#include<bits/stdc++.h>
using namespace std;
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},n,m;
int dfs(int x,int y,int f[],int a[],int d,int k){
    f[x][y]=1;
    if(k==0){
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(f[i][j]) sum++;
            }
        }
        return sum;
    }
    int xx=x+dx[d],yy=y+dy[d];
    if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]!=x){
        f[xx][yy]=1;
        return dfs(xx,yy,f[],a[],d,k-1);
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int k,f[100001][1000001]={},a[1000001][1000001]={},x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) cin>>a[i][j];
        }
        cout<<dfs(x,y,f,a,d,k);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}