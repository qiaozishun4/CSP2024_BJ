#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,ans,bx[4]={0,1,0,-1},by[4]={1,0,-1,0},b,x,y;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t>0){
        t--;
        cin>>n>>m>>k;
        cin>>x>>y>>b;
        char a[n+3][m+3];
        int  vis[n+3][m+3];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                vis[i][j]=0;
            }
        }
        vis[x][y]=1;
        ans++;
        while(k>0){
            k--;
            if(x+bx[b]>=1&&x+bx[b]<=n&&y+by[b]>=1&&y+by[b]<=m&&a[x+bx[b]][y+by[b]]!='x'){
                x=x+bx[b];
                y=y+by[b];
                if(vis[x][y]==0){
                    ans++;
                    vis[x][y]=1;
                }
            }else{
                b=(b+1)%4;
            }
        }
        cout<<ans<<endl;
        ans=0;
    }

    return 0;
}