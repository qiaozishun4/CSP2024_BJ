#include <bits/stdc++.h>
using namespace std;
int n;
int a[50];
int s[50];
int maxn = 0;
void dfs(int i,int n){
	if (i > n){
		int ans = 0;
		for (int j = 1;j <= n;j++){
			int k = j - 1;
			for (;k >= 1;k--){
				if (s[k] == s[j]){
					if (a[k] == a[j]) ans += a[k];
					break;
				}
			}
		}
		maxn = max(maxn,ans);
		return ;
	}
	s[i] = 0;
	dfs(i + 1,n);
	s[i] = 1;
	dfs(i + 1,n);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin >> T;
	while (T--){
		maxn = 0;
		cin >> n;
		for (int i = 1;i <= n;i++) cin >> a[i];
		dfs(1,n);
		cout << maxn << endl;
	}
	return 0;
}
