#include <bits/stdc++.h>
using namespace std;
char b[100][100];
int n,m,k,t,f[1000][1000],cnt=0,cntt=1;
void dfs(int x,int y,int d){
    if(d==1&&y==m){
        d=2;
        cnt++;
        dfs(x,y,d);
    }
    else if(d==2&&x==1){
        d=3;
        cnt++;
        dfs(x,y,d);
    }
    else if(d==3&&y==1){
        d=0;
        cnt++;
        dfs(x,y,d);
    }
    else if(d==0&&x==n){
        d=3;
        cnt++;
        dfs(x,y,d);
    }


    if(d=0&&b[x][y+1]=='x'){
        d=1;
        cnt++;
        dfs(x,y,d);
    }
    else if(d=1&&b[x-1][y]=='x'){
        d=2;
        cnt++;
        dfs(x,y,d);
    }
    else if(d=2&&b[x][y-1]=='x'){
        d=3;
        cnt++;
        dfs(x,y,d);
    }
    else if(d=3&&b[x+1][y]=='x'){
        d=0;
        cnt++;
        dfs(x,y,d);
    }


    if(d=0){
        cnt++;
        f[x][y]=1;
        cntt++;
        dfs(x+1,y,d);
    }
    else if(d=1){
        cnt++;
        f[x][y]=1;
        cntt++;
        dfs(x,y+1,d);
    }
    else if(d=2){
        cnt++;
        f[x][y]=1;
        cntt++;
        dfs(x-1,y,d);
    }
    else if(d=3){
        cnt++;
        f[x][y]=1;
        cntt++;
        dfs(x,y-1,d);
    }
    if(cnt==k){
        return;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    int x0,y0,d0;
    while(t--){
        cin>>n>>m>>k;
        cin>>x0>>y0>>d0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>b[i][j];
                f[i][j]=0;
            }
        }
        dfs(x0,y0,d0);
        cout<<cntt<<endl;
    }
    return 0;
}
