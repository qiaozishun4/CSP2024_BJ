#include<bits/stdc++.h>
using namespace std;
int t;
int dis[4][2]={0,1,1,0,0,-1,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int n,m,k,ans=0;
        int vis[1005][1005];
        memset(vis,0,sizeof(vis));
        char a[1005][1005];
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        vis[x][y]=d+1;
        for(int i=1;i<=n;i++){
                string s;
                cin>>s;
                for(int j=1;j<=m;j++){
                    a[i][j]=s[j-1];
                }
        }
        while(k){
            int flag=0;
            for(int i=d;i<d+4;i++){
                if(k==0)break;
                int fx=x+dis[i%4][0],fy=y+dis[i%4][1];
                if(fx>=1&&fx<=n&&fy>=1&&fy<=m&&a[fx][fy]=='.'){
                    if(vis[fx][fy]==i%4+1){
                        flag=0;
                        break;
                    }
                    k--;
                    vis[fx][fy]=i%4+1;
                    x=fx;
                    y=fy;
                    flag=1;
                    d=i%4;
                    break;
                }
                k--;
            }
            if(flag==0){
                 break;
            }

        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]){
                        ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
