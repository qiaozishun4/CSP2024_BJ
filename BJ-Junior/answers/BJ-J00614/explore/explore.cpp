#include<iostream>
#include<cstring>
typedef long long ll;
using namespace std;
bool a[1005][1005],vis[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ll t,k,ans,n,m,x,y,d;
    char aa;
    cin>>t;
    while(t--){
        memset(vis,false,sizeof(vis));
        ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        vis[x][y]=true;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                cin>>aa;
                if(aa=='x'){
                    a[i][j]=false;
                }
                else{
                    a[i][j]=true;
                }
            }
        }
        ll xx,yy,dd;
        while(k--){
            if(d==0){
                xx=x;
                yy=y+1;
            }
            else if(d==1){
                xx=x+1;
                yy=y;
            }
            else if(d==2){
                xx=x;
                yy=y-1;
            }
            else{
                xx=x-1;
                yy=y;
            }
            //cout<<xx<<" "<<yy<<endl;
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]==true){
                x=xx;
                y=yy;
                if(vis[xx][yy]==false){
                    ans++;
                    vis[xx][yy]=true;
                }
            }
            else{
                d=(d+1)%4;
            }
            //cout<<x<<" "<<y<<" "<<d<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
