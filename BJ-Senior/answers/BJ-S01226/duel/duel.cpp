#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005],mp[100005],b[100005],ans,cnt;
int cmp(ll x,ll y)
{
    return x>y;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],mp[a[i]]++;
	sort(a+1,a+n+1);
	ll pos=unique(a+1,a+n+1)-a;
	ll m=0;
	for(int i=pos-1;i>=1;i--)
    {
        b[++m]=mp[a[i]];
    }
    for(int i=1;i<=m;i++)
    {
        //cout<<b[i]<<' ';
        if(cnt>=b[i])
        {b[i]=0;continue;}
        b[i]-=cnt;
        ans+=b[i];
        cnt+=b[i];
    }cout<<ans;
	return 0;
}
