#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,x,maxx=-2e9,minx=2e9,cnt,last,da;
    cin>>n;
    cnt=n;
    for(int i=1;i<=n;i++)cin>>x,a[x]++,maxx=max(maxx,x),minx=min(minx,x);
    last=minx,da=a[minx];
    for(int i=minx+1;i<=maxx;i++)
    {
        if(a[i])
        {
            if(a[i]>=da)cnt-=da,da=a[i];
            else cnt-=a[i];
        }
        if(cnt<=0)
        {
            cout<<0;
            return 0;
        }
    }
    cout<<cnt;
}