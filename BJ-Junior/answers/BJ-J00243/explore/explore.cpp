#include<bits/stdc++.h>
using namespace std;
int dx[5]={0,1,0,-1};
int dy[5]={1,0,-1,0};
int T;
int n,m,k;
int x,y,d;
bool a[1005][1005];
long long ans;
char v[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) cin>>v[i][j];
        }
        a[x][y]=true;
        for(int i=1;i<=k;i++){
            if((x+dx[d]>=1 && x+dx[d]<=n) && (y+dy[d]>=1 && y+dy[d]<=m) && v[x+dx[d]][y+dy[d]]=='.'){
                x+=dx[d];
                y+=dy[d];
                a[x][y]=true;
            }
            else d=(d+1)%4;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) ans+=a[i][j],v[i][j]=a[i][j]=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
