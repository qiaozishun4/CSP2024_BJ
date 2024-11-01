#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,xx,yy,dd,dx[8]={0,1,0,-1},dy[8]={1,0,-1,0},ans;
char a[1005][1005];
bool flag[1005][1005];
int main()
{
	freopen ("explore.in","r",stdin);
	freopen ("explore.out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n>>m>>k>>xx>>yy>>dd;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        ans=1;
        flag[xx][yy]=1;
        int kk=k,x=xx,y=yy,d=dd;
        while (kk)
        {
            int tx=x+dx[d],ty=y+dy[d];
            if (tx>=1&&ty>=1&&tx<=n&&ty<=m&&a[tx][ty]=='.')
            {
                if (!flag[tx][ty])
                {
                    ans++;
                    flag[tx][ty]=1;
                }
                kk--;
                x=tx;
                y=ty;
            }
            else
            {
                kk--;
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
        memset (flag,0,sizeof (flag));
    }
	return 0;
}
