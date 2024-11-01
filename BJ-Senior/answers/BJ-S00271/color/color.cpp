#include<iostream>
#include<map>
using namespace std;
const int N = 1e5 + 2;
int n;
int a[N];
int dfs(int m, int r, int b, int ans){
	if(m == n + 1){
		return ans;
	}
	return max(dfs(m + 1, a[m], b, ans + a[m] * (r == a[m])), dfs(m + 1, r, a[m], ans + a[m] * (b == a[m])));
}
void mian(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cout << dfs(1, 0, 0, 0) << endl;
}
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		mian();
	}
}