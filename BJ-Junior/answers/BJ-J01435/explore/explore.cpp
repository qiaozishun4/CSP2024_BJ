#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
char a[1005][1005];
bool b[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=k;i++)
        {
            if(d%4==0)
            {
                if(a[x][y+1]=='.'&&y+1<=m)
                {
                    b[x][y]=true;
                    y+=1;
                }
                else
                {
                    ++d;
                }
            }
            if(d%4==1)
            {
                if(a[x+1][y]=='.'&&x+1<=n)
                {   
                    b[x][y]=true;
                    x+=1;
                }
                else
                {
                    ++d;
                }
            }
            if(d%4==2)
            {
                if(a[x][y-1]=='.'&&y-1>=0)
                {
                    b[x][y]=true;
                    y-=1;
                }
                else
                {
                    ++d;
                }
            }
            if(d%4==3)
            {
                if(a[x-1][y]=='.'&&x-1>=0)
                {
                    b[x][y]=true;
                    x-=1;
                }
                else
                {
                    ++d;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(b[i][j])
                {
                    ++ans;
                }
            }
        }
        cout<<ans<<endl;
    }
}