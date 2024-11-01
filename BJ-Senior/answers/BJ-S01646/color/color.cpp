#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], ans = 0;
bool choose[N];
void dfs(int cur){
	if(cur > n){
		int tmp = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i - 1; j; j--)
				if(!(choose[i] ^ choose[j])){
					if(a[i] == a[j]) tmp += a[i];
					break;
				}
		ans = max(tmp, ans);
		return;
	}
	choose[cur] = 0;
	dfs(cur + 1);
	choose[cur] = 1;
	dfs(cur + 1);
	return;
}
void solve(){
	memset(a, 0, sizeof(a)), memset(choose, 0, sizeof(choose));
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	ans = 0;
	dfs(1);
	printf("%d", ans);
	return;
}
void open(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	return;
}
void close(){
	fclose(stdin);
	fclose(stdout);
	return;
}
int main(){
	open();
	int t;
	scanf("%d", &t);
	while(t--) solve(), printf("\n");
	close();
	return 0;
}