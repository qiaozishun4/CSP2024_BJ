#include<iostream>
#include<cstdio>
using namespace std;
int a[10010],n,ans,maxn,maxl,maxr;
void dfs(int l,int r)
{
    maxn=0,maxl=0,maxr=0;
    for(int i=l+1;i<=r;i++)
    {
        for(int j=l;j<i;j++)
        {
            if(a[i]==a[j]&&a[i]>=maxn)
            {
                maxn=a[i];
                maxl=j;
                maxr=i;
                continue;
            }
        }
    }
    if(maxn==0)
    {
        ans=0;
    }
    else{
        ans+=maxn;
        for(int i=maxl;i<maxr;i++)
        {
            if(a[i]==a[i-1])
            {
                ans+=a[i];
            }
        }
    }
    return;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
            a[i]=0;
        }
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        dfs(1,n);
        cout<<ans<<endl;
    }
    return 0;
}
