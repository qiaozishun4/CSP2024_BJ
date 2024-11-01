#include <bits/stdc++.h>
using namespace std;
int n,m,t,x,y,d,k,mp[1008][1008],h[1008][1008],u[4]={0,1,0,-1},v[4]={1,0,-1,0},ans=1;;
char c;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        ans=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                h[i][j]=0;
                mp[i][j]=0;
                cin>>c;
                if(c=='.'){
                    mp[i][j]=1;
                }
            }
        }
        h[x][y]=1;
        for(int i=1;i<=k;i++){
            int xx=x+u[d];
            int yy=y+v[d];
            if(mp[xx][yy]==1){
                if(h[xx][yy]==0){
                    h[xx][yy]=1;
                    ans++;
                }
                x=xx;
                y=yy;
            }else{
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
