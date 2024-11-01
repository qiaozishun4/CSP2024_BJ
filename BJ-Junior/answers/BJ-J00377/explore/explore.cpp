#include<iostream>
using namespace std;
char a[1000][1000];
int n,m,k;
bool vis[1000][1000];
int dx[70] = {0,1,0,-1},dy[70] = {1,0,-1,0};
void ans(int x,int y,int d)
{
    int cnt = 1;
    while(k--)
    {
        int xp = x + dx[d],yp = y + dy[d];
        if(xp<1||xp>n||yp<1||yp>m||a[xp][yp] == 'x')
        {
            d = (d+1)%4;
            xp = x + dx[d];
            yp = y + dy[d];
        }
        else
        {
            if(vis[xp][yp] == 0)cnt++;
            vis[xp][yp] = 1;
            x = xp;
            y = yp;
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i = 1;i<=n;i++)
        {
            string s;
            cin>>s;
            for(int j = 1;j<=m;j++)
            {
                a[i][j] = s[j-1];
                vis[i][j] = 0;
            }
        }
        ans(x,y,d);
    }
    return 0;
}