#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}},ans=0;
char mp[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            int o=x+dis[d][1],p=y+dis[d][2];
            if(o<=n&&o>0&&p<=m&&p>0&&mp[o][p]!='x'){
                mp[o][p]='v';
                x=o;
                y=p;
                //cout<<
            }
            else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j]=='v'){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
