#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k;
long long x,y,d;
bool f=1;
long long ans;
char a[1010][1010],b[1010][1010];
bool fangxiang()
{
    if(d==0)
    {
        if(a[x][y+1]!='x'&&y+1<=n)
        {
            y++;
            return 1;
        }
        else
        {
            d=(d+1)%4;
            return 0;
        }
    }
    if(d==1)
    {
        if(a[x+1][y]!='x'&&x+1<=m)
        {
            x++;
            return 1;
        }
        else
        {
            d=(d+1)%4;
            return 0;
        }
    }
    if(d==2)
    {
        if(a[x][y-1]!='x'&&y-1>0)
        {
            y--;
            return 1;
        }
        else
        {
            d=(d+1)%4;
            return 0;
        }
    }
    if(d==3)
    {
        if(a[x-1][y]!='x'&&x-1>0)
        {
            x--;
            return 1;
        }
        else
        {
            d=(d+1)%4;
            return 0;
        }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++)
        {
            for(int k1=1;k1<=m;k1++)
            {
                cin>>a[j][k1];
                b[j][k1]=0;
            }
        }
        ans++;
        for(int j=1;j<=k;j++)
        {
            f=fangxiang();
            if(f)
            {
                //cout<<x<<" "<<y<<endl;
                if(b[x][y]==0)
                {
                    ans++;
                    b[x][y]=1;
                }
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*2
 1 5 4
 1 1 2
 ....x
 5 5 20
 1 1 0
 .....
 .xxx.
 .x.x.
 ..xx.
 x....*/
