#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], n, clr[maxn];
int ans = -1;

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out","w",stdout);
	int T; cin >> T;
	while(T--){
		cin >> n;
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		ans = -1;
		for(int mask = 0; mask < (1 << n); ++mask){
			int sum = 0;
			for(int j = 0; j < n; ++j)
				clr[n - j - 1] = (mask >> j) & 1;
			for(int j = 0; j < n; ++j)
				for(int k = j - 1; ~k; --k)
					if(clr[j] == clr[k]){
						if(a[j] == a[k])
							sum += a[j];
						break;
					}
			ans = max(ans, sum);
		}
		cout << ans << '\n';
	}
	return 0;
}