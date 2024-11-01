#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,s;
char a[1005][1005];
int sx[4]={0,1,0,-1};
int sy[4]={1,0,-1,0};
int vis[1005][1005];
int ans[10];
int idx;
int sum=1;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios sync_with_std(0);
    cin.tie(0);cout.tie(0);
    int s;
    cin>>s;
    while(s--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++){
                a[i][j]='x';
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
        sum=1;
        vis[x][y]=1;
        int tx=x;
        int ty=y;
        int e=d;
        while(k>0){
            e=e%4;
            tx=x+sx[e];
            ty=y+sy[e];
            char q=a[tx][ty];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&q=='.'){
                    if(vis[tx][ty]==0){
                        sum++;
                        vis[tx][ty]=1;
                    }
                    x=tx;
                    y=ty;
                    k--;

                }
                else{
                e++;
                k--;


            }

        }
        ans[++idx]=sum;
    }
    for(int i=1;i<=idx;i++){
        cout<<ans[i]<<endl;
    }
return 0;
}

