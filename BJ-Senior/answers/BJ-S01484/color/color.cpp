#include <bits/stdc++.h>
#define int long long
using namespace std;
int T = 0;
int n = 0;
int a[200010];
int read(){
	int x = 0;
	int f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int tt[1000010];
int last[100010];
int pre[100010];
int dp[100010];
struct tree_node{
	int mx;
}t[400010];
void change(int x, int l, int r, int ps, int k){
	if(l == r){
		t[x].mx = k;
		return;
	}
	int mid = (l + r) >> 1;
	if(ps <= mid){
		change(x << 1, l, mid, ps, k);
	}
	else{
		change(x << 1 | 1, mid + 1, r, ps, k);
	}
	t[x].mx = max(t[x << 1].mx, t[x << 1 | 1].mx);
}
int query(int x, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr){
		return t[x].mx;
	}
	int mid = (l + r)  >> 1;
	int ans = 0;
	if(ql <= mid){
		ans = max(ans, query(x << 1, l, mid, ql, qr));
	}
	if(qr > mid){
		ans = max(ans, query(x << 1 | 1, mid + 1, r, ql, qr));
	}
	return ans;
}
signed main(){
freopen("color.in", "r", stdin);
freopen("color.out", "w", stdout);
	T = read();
	while(T --){
		n = read();
		for(int i = 1; i <= n; i++){
			a[i] = read();
			if(tt[a[i]]){
				last[i] = tt[a[i]];
			}
			tt[a[i]] = i;
		}
		dp[1] = 0;
		for(int i = 2; i <= n; i++){
			if(a[i] == a[i - 1]){
				pre[i] += a[i];
			}
			pre[i] += pre[i - 1];
		}
//		cout << endl;
		for(int i = 2; i <= n; i++){
//			cout << query(1, 1, n, 1, i - 1) - (pre[n] - pre[i - 1]) << " ! ";
			dp[i] = dp[i - 1] + a[i] * (a[i - 1] == a[i]);
			if(last[i] != i - 1){
				
			}
			dp[i] = max(dp[i], query(1, 1, n, 1, i - 1) - (pre[n] - pre[i - 1]));
			if(last[i]){
				if(last[i] == i - 1){
					dp[i] = max(dp[i], dp[last[i]] + a[i]);
				}
				else dp[i] = max(dp[i], dp[last[i]] + pre[i - 1] - pre[last[i] + 1] + a[i]);
			}
			
			change(1, 1, n, i, dp[i] + pre[n] - pre[i]);
		}
		cout << dp[n] << endl;
		for(int i = 1; i <= n; i++){
			pre[i] = 0;
			last[i] = 0;
			tt[a[i]] = 0;
			change(1, 1, n, i, 0);
		}
	}
	return 0;
}