#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int cnt[N];

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}

	int ans=0;
	for(int i=1;i<=100000;i++)
		ans=max(ans,cnt[i]);
	printf("%d\n",ans);
	return 0;
}