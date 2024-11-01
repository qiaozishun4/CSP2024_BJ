#include<bits/stdc++.h>
using namespace std;

int t;
int n,m,k,x,y,d;

int xx[]={0,1,0,-1};
int yy[]={1,0,-1,0};
int f[1010][1010];

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>t;
    while(t--){
        memset(f,0,sizeof(f));
        cin>>n>>m>>k>>x>>y>>d;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                if(c=='x')
                    f[i][j]=1;
            }
        }

        int nx=x;
        int ny=y;
        f[x][y]=2;

        while(k--){
            int tx=nx+xx[d];
            int ty=ny+yy[d];
            if(tx<1||tx>n||ty<1||ty>m||f[tx][ty]==1){
                d=(d+1)%4;
                continue;
            }
            nx=tx;
            ny=ty;
            f[tx][ty]=2;
        }

        int cnt=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(f[i][j]==2)
                    cnt++;

        cout<<cnt<<"\n";
    }
    return 0;
}
