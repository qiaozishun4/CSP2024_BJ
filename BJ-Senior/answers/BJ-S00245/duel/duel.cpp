#include<bits/stdc++.h>
using namespace std;
int a[100005],n;
int d[100005];
int ans=0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int maxx=-999;
    int minn=99999;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        d[a[i]]++;
        maxx=max(a[i],maxx);
        minn=min(a[i],minn);
    }
    int cnt=d[minn],ans=0;
    for(int i=minn+1;i<=maxx;i++)
    {
        if(d[i]==0)
        {
            continue;
        }
        if(cnt<=d[i])
        {
            ans+=cnt;
            cnt=d[i];
        }
        else if(cnt>d[i])
        {
            ans+=d[i];
        }
    }
    cout<<n-ans;
    return 0;
}
