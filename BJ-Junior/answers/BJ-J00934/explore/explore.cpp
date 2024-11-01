#include<bits/stdc++.h>
using namespace std;
int ans,n,m,t,k,d;
char a[1001][1001];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int x,y;
        ans=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++)
        for(int l=1;l<=m;l++){
            cin>>a[j][l];
        }
        for(;k!=0;k--){
            d%=4;
            int xx=x+dx[d],yy=y+dy[d];
            if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&a[xx][yy]=='.'){
                x=xx,y=yy;
                ans++;
            }else d++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
