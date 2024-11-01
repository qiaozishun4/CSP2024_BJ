#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn], vis[maxn], ans = 0;
void check(){
	int sum = 0;
	for(int i = 2 ; i <= n ; i++){
		int flag = -1;
		for(int j = 1 ; j <= i - 1 ; j++){
			if(vis[j] == vis[i]&& a[i] == a[j])flag = 1;
		}
		if(flag != -1)sum += a[i];
	}
	ans = max(sum, ans);
}
void dfs(int x){
	if(x > n){
		check();
		return ;
	}
	vis[x] = 1;
	dfs(x + 1);
	vis[x] = 2;
	dfs(x + 1);
	vis[x] = 0;
}
int main(){
	freopen("color.in", "r" , stdin);
	freopen("color.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		ans = n = 0;
		for(int i = 0 ; i < maxn ; i++)a[i] = vis[i] = 0;
		cin >> n;
		for(int i = 1 ; i <= n ; i++)cin >> a[i];
		dfs(1);
		cout << ans << endl;
	}
}
