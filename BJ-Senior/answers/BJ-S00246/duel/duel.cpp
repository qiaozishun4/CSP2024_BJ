#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 9;
pair<int, int> a[N];
int n, cc[N];

int main() {
  freopen("duel.in", "r", stdin);
freopen("duel.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    cc[a[i].first]++;
  }

  sort(a + 1, a + n + 1);
  int ans = 0, sum = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i].first != a[i - 1].first) {
      int u = cc[a[i].first], v = cc[a[i - 1].first];
      sum += v;
      if (sum < u) {
        ans += sum;
        sum = 0;
      } else {
        ans += u;
        sum -= u;
      }
    }
  }

  cout << n - ans << endl;
  return 0;
}