#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,k;
int x,y,d;
bool vis[N][N];
char c[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool check(int x,int y)
{
    if(x>n||x<0||y>m||y<0) return 0;
    else return c[x][y]=='.';
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {

        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        int cnt=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){cin>>c[i][j];vis[i][j]=0;}
        for(int i=1;i<=k;i++)
        {
            vis[x][y]=1;
            int px=dx[d]+x,py=dy[d]+y;
            if(check(px,py))
            {

                x=px;
                y=py;
            }
            else
            {
                d=(d+1)%4;
            }

        }
        vis[x][y]=1;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cnt+=vis[i][j];
        cout<<cnt<<endl;
    }

    return 0;
}
