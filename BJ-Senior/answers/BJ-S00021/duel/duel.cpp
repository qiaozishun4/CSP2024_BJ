#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

int n;
int a[100005], b[100005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("duel.in", "r", stdin);
  freopen("duel.out", "w", stdout);
  cin >> n;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[a[i]]++;
    mx = max(mx, b[a[i]]);
  }
  cout << mx << "\n";
  return 0;
}
