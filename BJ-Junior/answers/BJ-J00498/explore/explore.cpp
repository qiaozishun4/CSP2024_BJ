#include<bits/stdc++.h>
using namespace std;
char b[100][100];
int vis[100][100];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long t,n,m,k,x,y,d;
    cin>>t;
    while(t>=1){
        long long ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>b[i][j];
                vis[i][j]=0;
            }
        }
        while(k>=1){
            long long u,v;
            u=x;
            v=y;
            if(d==0) v+=1;
            else if(d==1) u+=1;
            else if(d==2) v-=1;
            else u-=1;
            if(u>=1&&u<=n&&v>=1&&v<=m&&b[u][v]=='.'){
                if(vis[u][v]==1) ans+=0;
                else{
                    if(d==0) y+=1;
                    else if(d==1) x+=1;
                    else if(d==2) y-=1;
                    else x-=1;
                    vis[x][y]=1;
                    ans+=1;
                }
            }
            else{
                d=(d+1)%4;
            }
            k--;
        }
        t--;
        cout<<ans<<endl;
    }
    return 0;
}