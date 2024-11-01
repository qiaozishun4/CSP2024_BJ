#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long x,y,d;
long long t;
char mp[1005][1005];
long long v[1005][1005];
void w(long long x,long long y,long long d,long long k){
    v[x][y]=1;
    if(k==0){
        return;
    }
    long long xx,yy;
    if(d==0){
        xx=x,yy=y+1;
    }else if(d==1){
        xx=x+1,yy=y;
    }else if(d==2){
        xx=x,yy=y-1;
    }else if(d==3){
        xx=x-1,yy=y;
    }
    if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&mp[xx][yy]!='x'){
        w(xx,yy,d,k-1);
    }else{
        long long dd=(d+1)%4;
        w(x,y,dd,k-1);
    }
}
long long ans=0;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(long long o=1;o<=t;o++){
        memset(mp,0,sizeof(mp));
        memset(v,0,sizeof(v));
        ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        w(x,y,d,k);
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                if(v[i][j]==1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
