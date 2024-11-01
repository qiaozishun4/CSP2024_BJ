#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;
char a[N][N];
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,x,y,d,dx,dy,sum=1;
        bool vis[1001][1001]={};
        cin>>n>>m>>k>>x>>y>>d;
        vis[x][y]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
            cin>>a[i][j];
        }
        for(int i=1;i<=k;i++){
            if(d==0)
                dx=x,dy=y+1;
            else if(d==1)
                dx=x+1,dy=y;
            else if(d==2)
                dx=x,dy=y-1;
            else
                dx=x-1,dy=y;
            if(dx<1||dx>n||dy<1||dy>m||a[dx][dy]=='x')
                d=(d+1)%4;
            else if(!vis[dx][dy]){
                sum++;
                x=dx,y=dy;
                vis[dx][dy]=true;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}