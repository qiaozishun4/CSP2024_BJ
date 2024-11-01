#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;

int t;
int n,m,k;
int x,y,d;

char a[1005][1005];
bool v[1005][1005];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        memset(v,0,sizeof v);
        ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)cin>>a[i][j];
        v[x][y]=1;
        for(int i=1;i<=k;i++){
            int xx=x+dx[d],yy=y+dy[d];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]!='x'){
                v[xx][yy]=1;
                x=xx,y=yy;
            }
            else d=(d+1)%4;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)ans+=v[i][j];
        cout<<ans<<'\n';
    }
    return 0;
}
