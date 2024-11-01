#include<bits/stdc++.h>
using namespace std;
long long n,mx,ans,cnt1[100005],cnt2[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        mx=max(mx,x);
        cnt1[x]++,cnt2[x]++;
    }
    for(long long i=1;i<mx;i++)
    {
        if(!cnt1[i])
        {
            continue;
        }
        for(long long j=i+1;j<=mx;j++)
        {
            if((!cnt1[j])||(!cnt2[j]))
            {
                continue;
            }
            if(cnt2[j]<cnt1[i])
            {
                cnt1[i]-=cnt2[j];
                cnt2[j]=0;
            }
            else
            {
                cnt2[j]-=cnt1[i];
                cnt1[i]=0;
                break;
            }
        }
    }
    for(long long i=1;i<=mx;i++)
    {
        ans+=cnt1[i];
    }
    cout<<ans;
    return 0;
}
