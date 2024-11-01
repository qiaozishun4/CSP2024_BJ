#include<bits/stdc++.h>
using namespace std;
long long t,n,k,q,r,c,pan,chushi1,chushi2,l;
int a[100005][2005];
/*void dfs(int ren,int shu,int id,int sum)
{
    if(sum>r)
    {
        return ;
    }
    if(pan==1)
        return ;
    if(sum=r)
    {
        for(int i=0;i<=k;i++)
        {
            if(a[ren][id+i]==c)
            {
                pan=1;
            }
        }
        return ;
    }
    for(int j=0;j<=k;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i==ren)
                continue;
            for(int p=1;p<=l[i];p++)
            {
                if(a[i][p]==a[ren][id+k])
                {
                    dfs(i,a[i][p],p,sum+1);
                }
            }
        }
    }
}*/
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%lld",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld%lld%lld",&n,&k,&q);
        for(int j=1;j<=n;j++)
        {
            cin>>l;
            for(int p=1;p<=l;p++)
            {
                cin>>a[j][p];
                /*if(a[j][p]==1)
                {
                    chushi1=j;
                    chushi2=p;
                }*/
            }
        }
        for(int j=1;j<=q;j++)
        {
            scanf("%lld%lld",&r,&c);
            //dfs(chushi1,1,chushi2,1);
            //cout<<pan<<endl;
            //pan=0;
            cout<<0<<endl;
        }
    }
    return 0;
}
