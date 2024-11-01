#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
const ll INF = 0x3f3f3f3f, mod = 998244353;

int n, a[N];
int cnt[N];
vector<int> vec;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i], cnt[a[i]] ++, vec.push_back(a[i]);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    int nums = 0, res = 0;
    for (auto x: vec)
    {
        res += min(cnt[x], nums);
        nums -= min(cnt[x], nums), nums += cnt[x];
    }
    cout << n - res << '\n';
    return 0;
}