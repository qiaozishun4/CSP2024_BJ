#include<bits/stdc++.h>
using namespace std;
char a[1000][1000];
int pos[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int vis[1000][1000];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        int cnt=1;
        for(int i=1;i<=k;i++){
            if(x+pos[d][0]>n||y+pos[d][1]>m||x+pos[d][0]<=0||y+pos[d][1]<=0||a[x+pos[d][0]][y+pos[d][1]]=='x'){
                d=(d+1)%4;
            }else{
                x=x+pos[d][0];
                y=y+pos[d][1];
                if(vis[x][y]==0){
                    vis[x][y]=1;
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
    }
}
