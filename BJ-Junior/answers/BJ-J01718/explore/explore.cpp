#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAXNM=1050;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ll T;
    cin>>T;
    while(T--){
        ll n,m,k,dg0,xg0,yg0;
        char a[MAXNM][MAXNM]={};
        bool p[MAXNM][MAXNM]={};
        memset(p,0,sizeof(p));
        ll cmt=0;
        cin>>n>>m>>k;
        cin>>xg0>>yg0>>dg0;
        ll dnw=dg0,xnw=xg0,ynw=yg0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<=k; ){
            if(p[xnw][ynw]==0){
                cmt++;
                p[xnw][ynw]=1;
            }
            for(int j=0;j<4;j++){
                ll nxtx=xnw,nxty=ynw;
                if(dnw==0) nxty++;
                else if(dnw==1) nxtx++;
                else if(dnw==2) nxty--;
                else if(dnw==3) nxtx--;
                if(a[nxtx][nxty]=='.'){
                    xnw=nxtx;
                    ynw=nxty;
                    i++;
                    break;
                }
                i++;
                if(k<i) break;
                dnw=(dnw+1)%4;
            }
        }
        cout<<cmt<<endl;
    }
    return 0;
}