#include<iostream>
using namespace std;
char v[1005][1005];
bool z[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        int n,m,k,x,y,t,ans=0;
        cin>>n>>m>>k>>x>>y>>t;
        for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>v[i][j];
        z[x][y]=1;
        while(k--){
            int x1=x,y1=y;
            if(t==0)++y1;
            if(t==1)++x1;
            if(t==2)--y1;
            if(t==3)--x1;
            if(1<=x1&&x1<=n&&1<=y1&&y1<=m&&v[x1][y1]=='.')x=x1,y=y1,z[x][y]=1;
            else t=(t+1)%4;
        }
        for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(z[i][j])++ans,z[i][j]=0;
        cout<<ans<<endl;
    }
}
