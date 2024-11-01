#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
#define MAXN 200050
using namespace std;
ll n,a[MAXN],cur[MAXN],ans=0;

void dfs(int pos)
{
    if (pos==n+1)
    {
        ll tmp=0;
        int p0=0,p1=0;
        for (int i=1;i<=n;i++)
        {
            if (cur[i]==0)
            {
                if (p0&&a[p0]==a[i]) tmp+=a[i];
                p0=i;
            }
            else if (cur[i]==1)
            {
                if (p1&&a[p1]==a[i]) tmp+=a[i];
                p1=i;
            }
        }
        ans=max(ans,tmp);
        return ;
    }
    cur[pos]=0;
    dfs(pos+1);
    cur[pos]=1;
    dfs(pos+1);
}

void solve()
{
    ans=0;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    dfs(1);
    cout<<ans<<endl;
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    int T;
    cin>>T;
    while (T--) solve();
    fclose(stdin);
    fclose(stdout);

    return 0;
}
