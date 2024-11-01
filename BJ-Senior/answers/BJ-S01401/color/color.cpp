#include<iostream>
#include<cstring>
const long long N = 1e5 + 5;
long long T;
long long a[N];
long long color[N];

long long ans = 0;
void dfs(long long cur, long long n){
	if(cur > n){
		long long res = 0;
		long long last[2] = {0, 0};
		for(long long i = 1; i <= n; i ++){
			if(last[color[i]] && a[i] == last[color[i]]){
				res += a[i];
			}
			last[color[i]] = a[i];
		}
		ans = std::max(ans, res);
		return ;
	}
	for(long long i = 0; i < 2; i ++){
		color[cur] = i;
		dfs(cur+1, n);
	}
}

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%lld", &T);
	while(T --){
		long long n;
		scanf("%lld", &n);
		for(long long i = 1; i <= n; i ++){
			scanf("%lld", &a[i]);
		}
		dfs(1, n);
		printf("%lld\n", ans);
		ans = 0;
		memset(a, 0, sizeof(a));
		memset(color, 0, sizeof(color));
	}
	return 0;
}