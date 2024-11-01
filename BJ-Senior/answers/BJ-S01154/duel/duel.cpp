#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],cnt[100005],sum[100005],num[100005];
signed main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cnt[a[i]]++,num[a[i]]=cnt[a[i]];
    for(int i=2;i<=1e5;i++)
    {
        if(cnt[i]>cnt[i-1])
        {
            num[i-1]=0;
            cnt[i]-=num[i-1];
            sum[i]=sum[i-1];
            sum[i]=max(sum[i]-cnt[i],(int)0);
        }
        else
        {
            num[i-1]-=num[i];
            sum[i]=sum[i-1]+num[i-1];
        }
    }
    cout<<sum[100000]<<endl;
    return 0;
}
