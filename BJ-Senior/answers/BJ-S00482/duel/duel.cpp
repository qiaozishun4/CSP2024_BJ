#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int N=1e5+10;
int a[N];
bool vis[N];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int ans=n,p;
    p=upper_bound(a+1,a+1+n,a[1])-a;
    for(int i=1;i<n;i++)
    {
        while((vis[p]||a[p]<=a[i])&&p<=n)p++;
        if(vis[p]||p>n)break;
        vis[p]=1;
        ans--;
    }
    cout<<ans;
    return 0;
}
