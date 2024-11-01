#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],ans=0;
bool die[N],vis[N];
inline int BinarySearch(int x)
{
	int l=1,r=n,ans=-1;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (a[mid]<=x||die[mid]||vis[mid]) l=mid+1;
		else ans=mid,r=mid-1;
	}
	return ans;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		int j=BinarySearch(a[i]);
		if (j!=-1) die[i]=1,vis[j]=1;
	}
	for (int i=1;i<=n;i++)
		if (!die[i]) ans++;
	cout<<ans<<"\n";
	return 0;
}