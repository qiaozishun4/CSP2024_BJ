#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],n;
bool f[N];
int l,r,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	l=1,r=2;
	while(l<=r&&r<=n&&l<=n){
		if(a[r]>a[l]){
			ans++;
			l++,r++;
		}else r++;
	}
	cout << n-ans;
	return 0;
}