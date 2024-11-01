#include <iostream>
#include <algorithm>
#define N 100001

using namespace std;

int n, p = 1, ans, a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("duel.in", "r", stdin);
  freopen("duel.out", "w", stdout);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];

  sort(a+1, a+n+1);
  for(int i = 2; i <= n; i++)
    if(a[p] < a[i]) p++, ans++;
  cout << n - ans << '\n';
}