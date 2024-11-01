#include <iostream>
#include <vector>
using namespace std;
int l[100005];
vector<int> z1[200005],z2[200005];
vector<bool> f[100005],w[100005];
bool ans[105][100005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,k,q,x,r,c,lst,sz,s,g,i,j,k2;
    bool h;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&l[i]);
            lst=-1;
            for(j=0;j<l[i];j++)
            {
                scanf("%d",&x);
                z1[x].push_back(i);
                z2[x].push_back(j);
                f[i].push_back(0);
                w[i].push_back(0);
                if(lst!=-1&&j-lst<k)
                    f[i][j]=ans[i][x]=1;
                else
                    ans[i][x]=0;
                if(x==1)
                    lst=j;
            }
        }
        for(i=2;i<=100;i++)
        {
            for(j=1;j<=200000;j++)
            {
                sz=z1[j].size(),s=g=h=0;
                for(k2=0;k2<sz;k2++)
                    if(f[z1[j][k2]][z2[j][k2]])
                    {
                        if(g!=0&&z1[j][k2]!=g)
                            h=1;
                        if(g==0)
                            g=z1[j][k2];
                        s++;
                    }
                if(s==0)
                    for(k2=0;k2<sz;k2++)
                        w[z1[j][k2]][z2[j][k2]]=0;
                if(s!=0&&!h)
                    for(k2=0;k2<sz;k2++)
                        if(z1[j][k2]!=g)
                            w[z1[j][k2]][z2[j][k2]]=1;
                        else
                            w[z1[j][k2]][z2[j][k2]]=0;
                if(h)
                    for(k2=0;k2<sz;k2++)
                        w[z1[j][k2]][z2[j][k2]]=1;
            }
            for(j=1;j<=n;j++)
            {
                s=0;
                for(k2=0;k2<l[j];k2++)
                {
                    if(k2>=k&&w[j][k2-k])
                        s--;
                    if(s>0)
                        f[j][k2]=1;
                    else
                        f[j][k2]=0;
                    if(w[j][k2])
                        s++;
                }
            }
            for(j=1;j<=200000;j++)
            {
                sz=z1[j].size();
                ans[i][j]=0;
                for(k2=0;k2<sz;k2++)
                    if(f[z1[j][k2]][z2[j][k2]])
                        ans[i][j]=1;
            }
        }
        while(q--)
        {
            scanf("%d%d",&r,&c);
            printf("%d\n",ans[r][c]);
        }
        for(i=1;i<=n;i++)
        {
            f[i].clear();
            w[i].clear();
        }
        for(i=1;i<=200000;i++)
        {
            z1[i].clear();
            z2[i].clear();
        }
    }
    return 0;
}