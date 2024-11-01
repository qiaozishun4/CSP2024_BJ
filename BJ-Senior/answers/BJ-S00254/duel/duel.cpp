#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,cnt[100005],ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        cnt[a]++;
    }
    for(int i=1;i<=100000;i++)
    {
        ans=max(ans,cnt[i]);
    }
    cout<<ans<<endl;
    return 0;
}
