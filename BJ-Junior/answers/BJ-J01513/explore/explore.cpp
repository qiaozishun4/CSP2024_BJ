#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n1234;
    cin>>n1234;
    for(int jjj=0;jjj<n1234;jjj++)
    {
        int n,m,k,x,y,d,ans;
        cin>>n>>m>>k>>x>>y>>d;
        char a[n+2][m+2]={};
        int dt[n+2][m+2]={};
        dt[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=0;i<k;i++)
        {
            int nex,ney;
            switch(d)
            {
                case 0:
                    ney=y+1;
                    break;
                case 1:
                    nex=x+1;
                    break;
                case 2:
                    ney=y-1;
                    break;
                case 3:
                    nex=x-1;
                    break;
            }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
            if(nex>n||nex<1||ney>m||ney<1||a[nex][ney]=='x')
            {
                d=(d+1)%4;
            }
            else
            {
                x=nex;
                y=ney;
                dt[x][y]=1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                ans+=dt[i][j];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
