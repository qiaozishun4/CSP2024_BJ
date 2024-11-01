#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
char a[1002][1002];
bool vis[1002][1002];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                vis[i][j]=0;
            }
        }
        vis[x][y]=1;
        int ans=1;
        while(k--){
            int x1=x,y1=y;
            if(d==0){
                y1++;
            }
            else if(d==1){
                x1++;
            }
            else if(d==2){
                y1--;
            }
            else{
                x1--;
            }
            if(x1<1 || x1>n || y1<1 || y1>m || a[x1][y1]=='x'){
                d=(d+1)%4;
                continue;
            }
            x=x1;
            y=y1;
            if(!vis[x][y]){
                ans++;
                vis[x][y]=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}