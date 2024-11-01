#include <bits/stdc++.h>
using namespace std;
int sum,m,n;
bool vis[1005][1005];
char a[1005][1005];
void f(int x,int y,int d,int k)
{
    if(!vis[x][y])sum++;
    if(k==0)return ;
    vis[x][y]=1;
    if(d==0)
    {
        if(a[x][y+1]=='.'&&y+1<=m)f(x,y+1,0,k-1);
        else f(x,y,1,k-1);
    }
    if(d==1)
    {
        if(a[x+1][y]=='.'&&x+1<=n)f(x+1,y,1,k-1);
        else f(x,y,2,k-1);
    }
    if(d==2)
    {
        if(a[x][y-1]=='.'&&y-1>=1)f(x,y-1,2,k-1);
        else f(x,y,3,k-1);
    }
    if(d==3)
    {
        if(a[x-1][y]=='.'&&x-1>=1)f(x-1,y,3,k-1);
        else f(x,y,0,k-1);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int k,x,y,d;
        sum=0;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> a[i][j];
                vis[i][j]=0;
            }
        }
        f(x,y,d,k);
        cout << sum << endl;
    }
    return 0;
}