#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ll t,xnext,ynext,xb,yb;
    cin>>t;
    for(ll i=1;i<=t;++i){
        ll n,m,k;
        ll x,y,d0;
        cin>>n>>m>>k;
        cin>>x>>y>>d0;
        vector<vector<char>>vv(n+1,vector<char>(m+1));
        vector<vector<bool>>b(n+1,vector<bool>(m+1,false));
        for(ll j=1;j<=n;++j){
            for(ll l=1;l<=m;++l){
                cin>>vv[j][l];
            }
        }
        ll sum=1;
        b[x][y]=true;
        for(ll p=1;p<=k;++p){
            xb=x,yb=y;
            if(d0==0){
                ++y;
            }
            else if(d0==1){++x;}
            else if(d0==2){--y;}
            else if(d0==3){--x;}
            if(!(x>=1&&x<=n&&y>=1&&y<=m)){
                d0=(d0+1)%4;
                x=xb,y=yb;
                continue;
            }
            if(vv[x][y]=='x'){
                d0=(d0+1)%4;
                x=xb,y=yb;
                continue;
            }
            if(!b[x][y]){
                ++sum;
                b[x][y]=true;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
