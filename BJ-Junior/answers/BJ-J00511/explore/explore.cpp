#include <bits/stdc++.h>
using namespace std;
int q;
char a[1005][1005];
bool dis[1005][1005];
int n,m,k,x,y,d;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>q;
    while(q--){
        cin>>n>>m>>k>>x>>y>>d;
        int ans=1;
        memset(dis,0,sizeof(dis));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        int xn=x,yn=y,dn=d;
        dis[xn][yn]=1;
        while(k--){
            if(dn==0){
                if(yn+1<=m&&a[xn][yn+1]=='.'){
                    yn+=1;
                    if(!dis[xn][yn]){ans+=1;dis[xn][yn]=1;}
                }
                else dn=1;
            }

            else if(dn==1){
                if(xn+1<=n&&a[xn+1][yn]=='.'){
                    xn+=1;
                    if(!dis[xn][yn]){ans+=1;dis[xn][yn]=1;}
                }
                else dn=2;
            }
            else if(dn==2){
                if(yn-1>0&&a[xn][yn-1]=='.'){
                    yn-=1;
                    if(!dis[xn][yn]){ans+=1;dis[xn][yn]=1;}
                }
                else dn=3;
            }
            else if(dn==3){
                if(xn-1>0&&a[xn-1][yn]=='.'){
                    xn-=1;
                    if(!dis[xn][yn]){ans+=1;dis[xn][yn]=1;}
                }
                else dn=0;
            }
            //cout<<xn<<" "<<ans<<" "<<dn<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}