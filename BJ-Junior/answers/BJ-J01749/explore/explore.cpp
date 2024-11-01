#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,d,x,y,ans,comp[1005][1005];
char a[1005][1005];
int dfs(int x,int y,int d,int k){
    if(k==0)return ans;
    if(d==0&&a[x][y+1]=='.'&&y+1<=m){
        if(comp[x][y+1]==0)ans++;
        y++,k--;
        comp[x][y]=1;
        dfs(x,y,d,k);
    }
    else if(d==1&&a[x+1][y]=='.'&&x+1<=n){
        if(comp[x+1][y]==0)ans++;
        x++,k--;
        comp[x][y]=1;
        dfs(x,y,d,k);
    }
    else if(d==2&&a[x][y-1]=='.'&&y-1>=1){
        if(comp[x][y-1]==0)ans++;
        y--,k--;
        comp[x][y]=1;
        dfs(x,y,d,k);
    }
    else if(d==3&&a[x-1][y]=='.'&&x-1>=1){
        if(comp[x-1][y]==0)ans++;
        x--,k--;
        comp[x][y]=1;
        dfs(x,y,d,k);
    }
    else{
        d=(d+1)%4;
        k--;
        dfs(x,y,d,k);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                comp[i][j]=0;
            }
        }
        comp[x][y]=1;
        cout<<dfs(x,y,d,k)<<endl;
    }
    return 0;
}
