#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
int n,a[MAXN],vis[MAXN];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int tt=1;
    for(int i=1;i<=n;i++)
    {
        while(tt<=n && (a[i]>=a[tt] || vis[tt])) tt++;
        if(vis[tt] || a[i]>=a[tt])
        {
            cout<<n-i+1;
            break;
        }
        vis[tt]=1;
    }
    return 0;
}
