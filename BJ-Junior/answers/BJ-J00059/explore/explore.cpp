#include<bits/stdc++.h>
using namespace std;
int mp[4][2]={0,1,1,0,0,-1,-1,0};
int h[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        memset(h,0,sizeof(h));
        char a[1005][1005];
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) cin>>a[i][j];
        }
        h[x][y]=1;
        while(k--){
            int nx=x+mp[d][0],ny=y+mp[d][1];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.') h[nx][ny]++,x=nx,y=ny;
            else d=(d+1)%4;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(h[i][j]>0) cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
