#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
struct jkl{
    int s,k;
}b[maxn];
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int tot = 1;
	b[1].s = a[1],b[1].k = 1;
	for (int i = 2; i <= n; i++) {
		if (b[tot].s == a[i]) {
			b[tot].k++;
		} else {
			b[++tot] = (jkl){a[i],1};
		}
	}
	int ans = 0,cnt = b[1].k;
	for (int i = 2; i <= tot; i++) {
		if (cnt <= b[i].k) {
			ans += cnt;
			cnt = b[i].k;
			
		} else {
			ans += b[i].k;
		}
	} 
	cout << n - ans << endl;
	return 0;
}
