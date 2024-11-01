#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;

int n;
int a[N],sum[N];

int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		sum[a[i]]++;
	} int m=*max_element(a+1,a+n+1),tot=0;
	for (int i=1; i<=m; i++) {
		tot=max(0,tot-sum[i]);
		tot+=sum[i];
	} cout<<tot<<'\n';
	return 0;
}
