#include<bits/stdc++.h>
using namespace std;
int n,m,l,w;
double b,c,e,f,g,q,r,s,ag;
int d[100005],a[100005],v[100005],p[100005],h[100005][100005],ab[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>n>>m>>l>>w;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i]>>a[i]>>v[i];
    }
    for(int j=1;j<=m;j++)
    {
        cin>>p[j];
    }
    for(int k=1;k<=n;k++)
    {
        e=v[k];
        s=0;
        while(b<=l)
        {
            for(int o=1;o<=m;o++)
            {
                if(p[o]>b)
                {
                    c=p[o]-b;
                    b=p[o];
                }
            }
            f=sqrt(pow(e)*2*a[k]*c)
            if(f>w)
            {
                s=1;
                g++;
                h[r][o]=1;
            }
        }
        if(s==1)
        {
            r++;
        }
    }
    for(int t=0;t<=r;t++)
    {
        int z=0;
        if(ab[t]!=0)
        {for(int u=1;u<=m;u++)
        {
            for(int x=t;x<=r;x++)
            {
                int y=0;
                if(h[t][u]==h[x][u])
                {
                    y++;
                }
            }
            if(y>z)
            {
                z=y;
                int ad=u;
            }

        }
        for(int ac=0;ac<=r,ac++)
        {
            if(h[t][ad]==h[ac][ad])
            {
                ab[ac]=0;
                ag++;
            }
        }
        }
    }
    cout<<g<<" "<<ag;
    return 0;
}
