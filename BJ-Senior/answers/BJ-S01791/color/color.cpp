#include <bits/stdc++.h>
using namespace std;
int a[200612];
int c[200612];
bool cl[200612];
int n,maxs=0;
int dfs(int d)
{
    int ans=0;
    if(d==n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j>=1;j--)
            {
                if(cl[i]==cl[j]&&a[i]==a[j])
                {
                    c[i]=a[i];
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans+=c[i];
        }
        maxs=max(maxs,ans);
        return maxs;
    }
    for(int i=0;i<=1;i++)
    {
        cl[d]=i;
        dfs(d+1);
    }
    return 0;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        maxs=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            cl[i]=0;
        }
        dfs(1);
        cout<<maxs<<endl;
    }
    return 0;
}
