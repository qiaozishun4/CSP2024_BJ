#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> p[200005];
int c[200005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T,n,k,t,x,r,v,fl;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&k,&t);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&c[i]);
            for(int j=1;j<=c[i];j++)
            {
                scanf("%d",&x);
                p[i].push_back(x);
            }
        }
        while(t--)
        {
            scanf("%d%d",&r,&v);
            if(r==0)
            {
                printf("0\n");
                continue;
            }
            if(r==1)
            {
                fl=0;
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<c[i]&&j<k;j++)
                    {
                        if(p[i][j]==v)
                        {
                            fl=1;
                            break;
                        }
                    }
                }
            }
            if(fl)
                printf("1\n");
            else
                printf("0\n");
        }
    }
    return 0;
}
