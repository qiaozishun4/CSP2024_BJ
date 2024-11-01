#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long ll;
int n,r[N],ans;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&r[i]);
	}
	sort(r+1,r+n+1);
	ans = n;
	int p = 1;
	for (int i = 2;i <= n;i++)
	{
		if (r[p] < r[i])
		{
			ans--;
			p++;
		}
	}
	printf("%d",ans);
	return 0;
}
