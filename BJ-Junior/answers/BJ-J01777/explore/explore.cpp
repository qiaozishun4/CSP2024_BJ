#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
int T,ans=0;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int num=0;num<T;num++)
    {
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        a[x][y]='!';
        for(int i=0;i<k;i++)
        {
            if(d==0)
                if(a[x][y+1]!='x'&&y+1<=m)
                {
                    y++;
                    a[x][y]='!';
                    continue;
                }
            if(d==1)
                if(a[x+1][y]!='x'&&x+1<=n)
                {
                    x++;
                    a[x][y]='!';
                    continue;
                }
            if(d==2)
                if(a[x][y-1]!='x'&&y-1!=0)
                {
                    y--;
                    a[x][y]='!';
                    continue;
                }
            if(d==3)
                if(a[x-1][y]!='x'&&x-1!=0)
                {
                    x--;
                    a[x][y]='!';
                    continue;
                }
            d=(d+1)%4;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(a[i][j]=='!')
                    ans++;
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
