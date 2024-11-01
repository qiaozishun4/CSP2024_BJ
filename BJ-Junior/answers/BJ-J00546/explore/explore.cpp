#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char a[1005][1005];
bool vis[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
       cin>>n>>m>>k;
       cin>>x>>y>>d;
       vis[x][y]=1;
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               cin>>a[i][j];
           }
       }
       int dx,dy;
       while(k--)
       {
           if(d==0)
           {
               dx=x;
               dy=y+1;
           }
           else if(d==1)
           {
               dx=x+1;
               dy=y;
           }
           else if(d==2)
           {
               dx=x;
               dy=y-1;
           }
           else if(d==3)
           {
               dx=x-1;
               dy=y;
           }
           if(dx>0&&dx<n+1&&dy>0&&dy<m+1&&a[dx][dy]=='.')
           {
               x=dx;
               y=dy;
               vis[x][y]=1;
           }
           else
           {
               d++;
               d%=4;
           }
       }
       int cnt=0;
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               if(vis[i][j]) cnt++;
           }
       }
       cout<<cnt<<endl;
       memset(vis,0,sizeof vis);
    }
    return 0;
}
