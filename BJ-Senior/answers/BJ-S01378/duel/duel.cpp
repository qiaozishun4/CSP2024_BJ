#include <bits/stdc++.h>
using namespace std;
int n,ans,a[100001],cnt[100001];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    for (int i=1;i<=100000;i++)
        if (cnt[i])
        {
            int x=cnt[i];
            for (int j=i-1;j>=0;j--)
            {
                if (cnt[j])
                {
                    int y=min(cnt[j],x);
                    cnt[j]-=y;
                    x-=y;
                }
                if (!x)
                    break;
            }
        }
    for (int i=0;i<=100000;i++)
    {
        ans+=cnt[i];
    }
    cout<<ans;
}