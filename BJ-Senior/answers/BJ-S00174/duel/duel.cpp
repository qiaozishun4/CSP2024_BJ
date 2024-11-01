#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
	int val,times;
}b[100010];
int n,a[100010],tot;
int main(void) {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) {
		if (a[i]==a[i-1]) b[tot].times++;
		else b[++tot]=Node{a[i],1};
	}
	int ans=0;
	for (int i=1;i<=tot;i++) {
		ans=max(0,ans-b[i].times);
		ans+=b[i].times;
	}
	cout << ans;
	return 0;
}