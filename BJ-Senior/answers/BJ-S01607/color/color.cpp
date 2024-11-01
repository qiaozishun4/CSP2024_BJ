#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5, A = 1e6+5;
int a[N];
ll dp[N];
bool mark[N];
int pre[N];
int lst[A];
int n;

int main(){
	ios::sync_with_stdio(0);
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	int T;
	
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		ll ans = 0;
		memset(mark, 0, sizeof(mark));
		memset(dp, 0, sizeof(dp));
		memset(lst, 0, sizeof(lst));
		memset(pre, 0, sizeof(pre));
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				mark[i] = 1;
				ans += a[i];
			}
		}
		int tot = 0;
		for(int i=1;i<=n;i++){
			if(!mark[i]) a[++tot] = a[i];
		}
		n = tot;
		for(int i=1;i<=n;i++){
			if(lst[a[i]]){
				pre[i] = lst[a[i]];
			}
			lst[a[i]] = i;
		}
		for(int i=2;i<=n;i++){
			dp[i] = dp[i-1];
			if(pre[i]) dp[i] = max(dp[i], dp[pre[i]+1]+a[i]);
		}
		cout << dp[n]+ans << endl;
	}
	
	return 0;
}
