#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k,x,y,d;
char a[1000+10][1000+10];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    for(cin>>T;T;T--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        int ans=1;
        bool vis[1000+10][1000+10]={};
        vis[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=k;i++)
        {
            //cout << "yes"<<endl;
            int x1,y1;
            if(d==0)
            {
                x1=x;
                y1=y+1;
            }
            else if(d==1)
            {
                x1=x+1;
                y1=y;
            }
            else if(d==2)
            {
                x1=x;
                y1=y-1;
            }
            else if(d==3)
            {
                x1=x-1;
                y1=y;
            }
            //cout << '#'<<x1<<' '<<y1<<' '<<d<<endl;
            if(a[x1][y1]=='x'||x1<1||y1<1||x1>n||y1>m)
            {
                d=(d+1)%4;
                //cout << '#'<<x1<<' '<<y1<<' '<<d<<endl;
            }
            else if(a[x1][y1]=='.')
            {
                x=x1;
                y=y1;
                if(vis[x1][y1]==0) ans++;
                vis[x1][y1]=1;
                //cout << '#'<<x1<<' '<<y1<<' '<<d<<endl;
            }
        }
        cout << ans<<endl;
    }

    return 0;
}
