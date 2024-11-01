#include <bits/stdc++.h>
using namespace std;

int T,mx[4]={0,1,0,-1},my[4]={1,0,-1,0};
bool a[1005][1005],vis[1005][1005];

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        int n,m,k,x,y,d,ans=0;
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                if(c=='.'){
                    a[i][j]=1;
                }
            }
        }
        vis[x][y]=1;
        for(int i=1;i<=k;i++){
            int x2=x+mx[d],y2=y+my[d];
            if(a[x2][y2] and !(x>n or x<1 or y>m or y<1)){
                x=x2;
                y=y2;
                vis[x][y]=1;
            }
            else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans+=vis[i][j];
            }
        }
        cout<<ans;
        if(T>0){
            cout<<"\n";
        }
    }
    return 0;
}
