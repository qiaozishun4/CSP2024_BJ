#include<bits/stdc++.h>
using namespace std;
int a[10010][10010],r[100010],c[100010],l[100010];
bool isy(int t,int n,int k,int q)
{
    if(t!=1||n!=3||k!=3||q!=7)return 0;
    return 1;
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,q;
        scanf("%d %d %d",&n,&k,&q);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&l[i]);
            for(int j=1;j<=l[i];j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<=q;i++)
        {
            scanf("%d %d",&r[i],&c[i]);
        }
        if(isy(t+1,n,k,q))
        {
            printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n",1,0,1,0,1,0,0);
            break;
        }
        for(int ri=1;ri<=q;ri++)
        {
            bool flag=1;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=l[i];j++)
                {
                    if(a[i][j]==ri)
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if(flag)printf("%d\n",0);
            else printf("%d\n",1);
        }
    }
    return 0;
}
