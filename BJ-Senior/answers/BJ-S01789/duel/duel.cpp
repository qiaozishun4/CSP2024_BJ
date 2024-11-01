#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,ans=0;
int a[N],cnt[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1]&&i!=1)
        {
            if(ans<i-1) ans+=min(i-1-ans,cnt[a[i]]);
        }
    }
    cout<<n-ans;
    return 0;
}
