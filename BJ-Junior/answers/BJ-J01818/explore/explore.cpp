#include <bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d;
long long a[1010][1010];
void dfs(long long x,long long y,long long d){
    long long cnt=0;
    if(d==0) y+=1;
    if(d==1) x+=1;
    if(d==2) y-=1;
    if(d==3) x-=1;
    if(x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]=='.'){
        cnt++;
        dfs(x,y,d);
    }
    else{
        dfs(x,y,(d+1)%4);
    }
    cout<<cnt;
    return;
}
int  main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        dfs(x,y,d);
    }
    return 0;
}
