#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
char ch[1001][1001];
bool vis[1001][1001];
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,k,x0,y0,d,ans=1;
        cin>>n>>m>>k>>x0>>y0>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>ch[i][j];
                vis[i][j]=0;
            }
        }
        vis[x0][y0]=1;
        ll nx,ny;
        while(k--)
        {
            if(d==0)
            {
                nx=x0;
                ny=y0+1;
            }
            if(d==1)
            {
                nx=x0+1;
                ny=y0;
            }
            if(d==2)
            {
                nx=x0;
                ny=y0-1;
            }
            if(d==3)
            {
                nx=x0-1;
                ny=y0;
            }
            if(nx>=1 && nx<=n && ny>=1 && ny<=m && ch[nx][ny]!='x')
            {
                x0=nx;
                y0=ny;
                if(!vis[nx][ny])
                {
                    vis[nx][ny]=1;
                    ans++;
                }
            }
            else
            {
                d++;
                if(d>3) d=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
