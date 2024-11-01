#include<iostream>
#include<cstring>
using namespace std;
char a[1010][1010];
char v[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void main2()
{
    memset(a,0,sizeof(a));
    memset(v,0,sizeof(v));
    int n,m,k;
    cin>>n>>m>>k;
    int x,y,d;
    cin>>x>>y>>d;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    int cnt=1;
    v[x][y]=1;
    while(k--)
    {
        int xx=x+dx[d],yy=y+dy[d];
        if(xx<1 || xx>n || yy<1 || yy>m || a[xx][yy]=='x')
        {
            d=(d+1)%4;
            continue;
        }
        x=xx;
        y=yy;
        if(v[x][y]==0)
        {
            cnt++;
            v[x][y]=1;
        }
    }
    cout<<cnt<<endl;
    return;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--) main2();
    return 0;
}
