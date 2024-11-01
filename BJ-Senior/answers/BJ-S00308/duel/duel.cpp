#include<bits/stdc++.h>
using namespace std;
int r[100010],cnt[100010],f[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,m=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
        cnt[r[i]]++;
    }
    for(int i=1;i<=100000;i++)
    {
        if(cnt[i]>0)
        {
            f[++m]=i;
        }
    }
    while(n>0)
    {
        for(int i=m;i>=1;i--)
        {
            if(cnt[f[i]]>0)
            {
                cnt[f[i]]--;
                n--;
            }
        }
        ans++;
    }
    cout<<ans;
    return 0;
}