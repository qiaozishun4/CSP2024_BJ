#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int r[N],vis[N],fight[N];
int ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&r[i]);
    sort(r+1,r+1+n);
    for(int i=1;i<n;i++)
    {
        vis[i]=1;
        int t=i;
        for(int j=i;j<=n;j++)
        {
            if(r[j]>r[i]&&!fight[j])
            {
                t=j;
                break;
            }
        }
        if(t==i)
        {
            fight[i+1]=1;
            vis[i]=0;
        }
        else
        {
            fight[t]=1;
        }
    }
    if(n%2)
    {
        for(int i=n-1;i>=1;i--)
        {
            if(!vis[i]&&r[i]<r[n])
            {
                vis[i]=1;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
