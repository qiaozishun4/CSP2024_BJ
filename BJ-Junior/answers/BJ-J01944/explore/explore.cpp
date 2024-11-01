#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll t,n,m,k,x,y,d,wayx[9]={0,1,0,-1},wayy[9]={1,0,-1,0};
ll nx,ny;
ll in[1005][1005];
char c[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int t1=1;t1<=t;t1++){
        memset(in,0,sizeof(in));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            scanf("%s",c[i]+1);
        }
        for(int i=1;i<=k;i++){
            in[x][y]=1;
            nx=x+wayx[d],ny=y+wayy[d];
            ll f=0;
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m){
                if(c[nx][ny]!='x'){
                    x=nx;
                    y=ny;
                    f=1;
                }
            }
            if(f==0){
                d=(d+1)%4;
            }
        }
        in[x][y]=1;
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(in[i][j]==1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

