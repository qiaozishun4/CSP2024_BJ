#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,k,x,y,f,ans;
int fx[]={0,1,0,-1};
int fy[]={1,0,-1,0};
char c[5010][5010];
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>f;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>c[i][j];
        ans=0;
        for(;k>=0;k--){
            if(c[x][y]=='.')ans++,c[x][y]='@';
            if((x+fx[f]<1||x+fx[f]>n)||(y+fy[f]<1||y+fy[f]>m)||c[x+fx[f]][y+fy[f]]=='x'){
                f=(f==3?0:f+1);
                continue;
            }
            x+=fx[f],y+=fy[f];
        }
        cout<<ans<<'\n';
    }
    return 0;
}