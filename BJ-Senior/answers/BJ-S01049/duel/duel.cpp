#include<bits/stdc++.h>
using namespace std;
long long n,r[100005],cnt[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    long long cnt1 = 0,cnt2 = 0;
    for(int i = 1;i <= n;i++)
    {
        cin>>r[i];
        cnt[r[i]]++;
    }
    cnt[0] = 0;
    long long pre = 0,ans = n;
    for(int i = 1;i <= 1e5;i++)
    {
        if(cnt[i] == 0) continue;
        if(cnt[i] >= cnt[pre]) ans -= cnt[pre];
        else ans -= cnt[i];
        pre = i;
    }
    cout<<ans<<endl;
    return 0;
}
