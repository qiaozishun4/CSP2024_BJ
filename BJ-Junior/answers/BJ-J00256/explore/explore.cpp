#include<bits/stdc++.h>
using namespace std;
char u[1010][1010];
long long s[1010][1010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(long long i=1;i<=n;i++)
        {
            for(long long j=1;j<=m;j++)
            {
                cin>>u[i][j];
            }
        }
        s[x][y]++;
        for(long long i=1;i<=k;i++)
        {
            if(d==0)
            {
                if(u[x][y+1]=='.')
                {
                    y++;
                }
                else d++;
            }
            else if(d==1)
            {
                if(u[x+1][y]=='.')
                {
                    x++;
                }
                else d++;
            }
            else if(d==2)
            {
                if(u[x][y-1]=='.')
                {
                    y--;
                }
                else d++;
            }
            else if(d==3)
            {
                if(u[x-1][y]=='.')
                {
                    x--;
                }
                else d=0;
            }
            s[x][y]++;
        }
        long long sum=0;
        for(long long i=1;i<=n;i++)
        {
            for(long long j=1;j<=m;j++)
            {
                if(s[i][j]!=0) sum++;
                s[i][j]=0;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
