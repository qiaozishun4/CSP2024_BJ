#include <iostream>
#define N 200005

using namespace std;

int t, n, a[N], v[N];
long long ans;

void dfs(int x) {
  if(x > n) {
    int l[3] = {};
    long long c = 0;
    for(int i = 1; i <= n; i++) {
      if(a[i] == a[l[v[i]]]) c += a[i];
      l[v[i]] = i;
    }
    ans = max(ans, c);
    return;
  }
  v[x] = 1, dfs(x+1);
  v[x] = 2, dfs(x+1);
}

int main() {
  freopen("color.in", "r", stdin);
  freopen("color.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  for(cin >> t; t; --t) {
    ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
      cin >> a[i];
    dfs(1);
    cout << ans << '\n';
  }
}