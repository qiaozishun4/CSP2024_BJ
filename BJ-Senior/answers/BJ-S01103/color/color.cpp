/*
#include <bits/stdc++.h>
using namespace std;
int tmp[100005],a[100005],m;
int ans;
void dfs(int x,int cnt,int rd,int bl)
{
    if(x>m)
    {
        ans=max(ans,cnt);
        return;
    }
    dfs(x+1,cnt+(a[rd]==a[x])*a[rd],x,bl);
    dfs(x+1,cnt+(a[bl]==a[x])*a[bl],rd,x);
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
        unordered_map<int,int> s;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>tmp[i];
            s[tmp[i]]++;
        }
        m=0;
        for(int i=1;i<=n;i++)
        {
            //if(s[tmp[i]]>=2)
            {
                a[++m]=tmp[i];
            }
        }/*
        for(int i=1;i<=m;i++)
        {
            cout<<a[i]<<" ";
        }
        dfs(1,0,0,0);
        cout<<ans<<"\n";
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int a[100005],sum[100005],n;
int ans;
void dfs(int x,int cnt,int rd,int bl)
{
    if(cnt+sum[n]-sum[x-1]<=ans)
    {
        return;
    }
    if(x>n)
    {
        ans=max(ans,cnt);
        return;
    }
    dfs(x+1,cnt+(a[rd]==a[x])*a[rd],x,bl);
    dfs(x+1,cnt+(a[bl]==a[x])*a[bl],rd,x);
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
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        dfs(1,0,0,0);
        cout<<ans<<"\n";
    }
    return 0;
}
