#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1009
using namespace std;
bool a[N][N];
bool b[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void mian()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int n,m,k;
    cin>>n>>m>>k;
    int x,y,d;
    cin>>x>>y>>d;
    for(int i=1; i<=n; i++)
    {
        string st;
        cin>>st;
        for(int j=0; j<m; j++)
        {
            if(st[j]=='.') a[i][j+1]=1;
        }
    }
    b[x][y]=true;
    for(int i=1; i<=k; i++)
    {
        int xx=x+dx[d];
        int yy=y+dy[d];
        if(a[xx][yy])
        {
            x=xx;
            y=yy;
            b[x][y]=true;
        }else{
            d=(d+1)%4;
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(b[i][j]) cnt++;
        }
    }
    cout<<cnt<<'\n';
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
        mian();
    return 0;
}
