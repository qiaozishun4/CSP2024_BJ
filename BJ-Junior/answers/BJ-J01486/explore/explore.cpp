#include<bits/stdc++.h>
using namespace std;
#define int long long
bool a[1009][1009];
bool jg[1009][1009];
inline void _main(){
int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<=n+3;i++){
        for(int j=0;j<=m+3;j++){
            a[i][j]=jg[i][j]=0;
        }
    }
    int x,y,d;
    cin>>x>>y>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char t;
            cin>>t;
            if(t=='.'){
                a[i][j]=1;
            }
        }
    }
    int ans;
    ans=1;
    jg[x][y]=1;
    while(k--){
        int xx,yy;
        xx=x,yy=y;
        if(d==0){
            yy++;
        }else if(d==1){
            xx++;
        }else if(d==2){
            yy--;
        }else{
            xx--;
        }
        if(a[xx][yy]){
            x=xx,y=yy;
        }else{
            d++;
            d%=4;
        }
        if(!jg[x][y]){
            ans++;
        }
        jg[x][y]=1;
    }
    cout<<ans<<endl;
}
signed main(){
    std::ios::sync_with_stdio(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        _main();
    }
    return 0;
}
