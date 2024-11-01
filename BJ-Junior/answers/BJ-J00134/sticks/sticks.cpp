#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
char a[1005][1005];
ll vis[1005][1005];
ll cnt=1;
ll n,m,k;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll x,y,d;
        scanf("%lld%lld%lld",&n,&m,&k);
        scanf("%lld%lld%lld",&x,&y,&d);
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(ll i=1;i<=n*m;i++){
            vis[x][y]=1;
            if(d==0&&a[x][y+1]=='.'&&y+1<=m){
                if(vis[x][y+1]==0){
                    cnt++;
                }else{
                    cnt++;
                    break;
                }
                y++;
 //               cout<<"x="<<x<<" y="<<y<<endl;
            }else if(d==1&&a[x+1][y]=='.'&&x+1<=n){
                if(vis[x+1][y]==0){
                   cnt++;
                }else{
                    cnt++;
                    break;
                }
                x++;
  //              cout<<"x="<<x<<" y="<<y<<endl;
            }else if(d==2&&a[x][y-1]=='.'&&y-1>=1){
                if(vis[x][y-1]==0){
                    cnt++;
                }else{
                    cnt++;
                    break;
                }
                y--;
//                cout<<"x="<<x<<" y="<<y<<endl;
            }else if(d==3&&a[x-1][y]=='.'&&x-1>=1){
                if(vis[x-1][y]==0){
                    cnt++;
                }else{
                    cnt++;
                    break;
                }
                x--;
//                cout<<"x="<<x<<" y="<<y<<endl;
            }else{
                d=(d+1)%4;
            }
        }
        printf("%lld\n",--cnt);
        memset(vis,0,sizeof(vis));
        cnt=1;
    }
    return 0;
}
