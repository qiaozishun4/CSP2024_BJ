#include "bits/stdc++.h"
using namespace std;
int n, a[100005],b[100005],nowk = 1, nowu = 2, ans, maxn = -1;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int t;
		cin >> t;
		a[t]++;
		b[t]++;
		maxn = max(maxn,t);
	}
	while(nowu <= maxn)
	{
		if(a[nowu] == 0 || nowu == nowk){
			nowu++;
			continue;
		}
		if(b[nowk] == 0){
			nowk++;
			continue;
		}
		if(a[nowu] >= b[nowk])	a[nowu] -= b[nowk],a[nowk] = b[nowk] = 0;
		else a[nowk] -= a[nowu],b[nowk] -= a[nowu],a[nowu] = 0;
	}
	for(int i = 1;i <= maxn;i++)	ans += b[i];
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
