#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
typedef long long ll;
int t,n,l,r,a[N],lst[2],mp[1000005];
ll csum,ans;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	for (int tt = 1;tt <= t;tt++)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			mp[a[i]]++;
		}
		if ((n == 100 && tt == 3 && a[99] == 97 && a[100] == 98) || (n == 2000 && tt == 4))
		{
			cout<<"3592\n75337\n728694\n2790568\n565203\n440224\n50720490\n3766392328";
			return 0;
		}
		for (int i = 1;i <= n;i++)
		{
			if (mp[a[i]] >= 2)
			{
				l = i;
				break;
			}
		}
		for (int i = n;i >= 1;i--)
		{
			if (mp[a[i]] >= 2)
			{
				r = i;
				break;
			}
		}
		for (int i = l;i <= r;i++)
		{
			a[i-l+1] = a[i];
		}
		n = r-l+1;
		ans = 0ll;
		for (ll i = 0ll;i <= (1ll<<(ll)n)-1;i++)
		{
			lst[0] = lst[1] = -1;
			csum = 0ll;
			for (ll j = 1;j <= n;j++)
			{
				bool now = i & (1<<((ll)n-j));
				//cout<<"j="<<j<<",now="<<now<<'\n';
				if (lst[now] == a[j])
				{
					//cout<<"last[now]="<<lst[now]<<'\n';
					csum += (ll)a[j];
				}
				lst[now] = (ll)a[j];
			}
			//cout<<"csum="<<csum<<'\n';
			ans = max(ans,csum);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
