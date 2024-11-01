#include<bits/stdc++.h>
using namespace std;
int n,m,k,t;
int mx,my,d;
char a[1005][1005];
bool u[1005][1005];
int ans;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    char tp;
    int tx,ty;
    while(t--)
    {
        memset(u,0,sizeof(u));
        ans=0;

        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&mx,&my,&d);
        my--;
        u[mx][my]=1;
        scanf("%c",&tp);
        for(int i=1;i<=n;i++)
        {
            cin.getline(a[i],1004);
        }
        /*for(int i=1;i<=n;i++)
        {
            cout<<a[i];
            cout<<endl;
        }*/
        for(int i=1;i<=k;i++)
        {
            if(d==0)
            {
                tx=mx;
                ty=my+1;
            }
            else if(d==1)
            {
                tx=mx+1;
                ty=my;
            }
            else if(d==2)
            {
                tx=mx;
                ty=my-1;
            }
            else
            {
                tx=mx-1;
                ty=my;
            }
            if(tx>0&&tx<=n&&ty>-1&&ty<m&&a[tx][ty]=='.')
            {
                u[tx][ty]=1;
                mx=tx;
                my=ty;
            }
            else
            {
                d+=1;
                d%=4;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(u[i][j]==1) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
