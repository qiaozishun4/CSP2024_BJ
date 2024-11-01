#include <bits/stdc++.h>
using namespace std;
int n;
int a[100050];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	int k = 1;
	for (int i = 2;i <= n;i++) if (a[i] > a[k]) k++;
	cout << n - k + 1 << endl;
	return 0;
}