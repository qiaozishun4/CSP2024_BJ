#include <bits/stdc++.h>
using namespace std;
char a[10010][10010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d;
    long long ans;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ans=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                cin>>a[j][k];
            }
        }
        a[x][y]='1';
        for(int j=1;j<=k;j++)
        {
            if(d==0)
            {
                if(a[x][y+1]=='.')
                {
                    ans++;
                    y++;
                    a[x][y]='1';
                }
                else if(a[x][y+1]=='1') y++;
                else d=(d+1)%4;
            }
            else if(d==1)
            {
                if(a[x+1][y]=='.')
                {
                    ans++;
                    x++;
                    a[x][y]='1';
                }
                else if(a[x+1][y]=='1') x++;
                else d=(d+1)%4;
            }
            else if(d==2)
            {
                if(a[x][y-1]=='.')
                {
                    ans++;
                    y--;
                    a[x][y]='1';
                }
                else if(a[x][y-1]=='1') y--;
                else d=(d+1)%4;
            }
            else
            {
                if(a[x-1][y]=='.')
                {
                    ans++;
                    x--;
                    a[x][y]='1';
                }
                else if(a[x-1][y]=='1') x--;
                else d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
