#include<bits/stdc++.h>
using namespace std;

int a[1010][2010],r[1010],c[1010],d[1010];

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(d,0,sizeof(d));
        int n,k,q;
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][0];
            for(int j=1;j<=a[i][0];j++)
                cin>>a[i][j];
        }
        bool f=true;
        for(int i=1;i<=q;i++)
        {
            cin>>r[i]>>c[i];
            if(r[i]!=1)
                f=false;
        }
        if(f)
        {
            for(int i=1;i<=n;i++)
            {
                bool ff=false,s;
                for(int j=1;j<=a[i][0];j++)
                {
                    if(ff==true && (j-s+1)<=k)
                    {
                        d[0]++;
                        d[d[0]]=a[i][j];
                    }
                    if(a[i][j]==1)
                    {
                        ff=true;
                        s=j;
                    }
                }
            }
            for(int i=1;i<=q;i++)
            {
                bool ff=false;
                for(int j=1;j<=d[0];j++)
                {
                    if(d[j]==c[i])
                    {
                        ff=true;
                        break;
                    }
                }
                if(ff)
                {
                    printf("1\n");
                }
                else
                    printf("0\n");
            }
        }
    }
    return 0;
}
