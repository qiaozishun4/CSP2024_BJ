#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 100010;
const int INF  = 0x3f3f3f3f;
const ll INFL  = 0x3f3f3f3f3f3f3f3f;
const double MMIN = 1e-6;
#define i128 __int128

int ai[MAXN], n;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> ai[i];
    sort(ai + 1, ai + 1 + n);
    int l = 0;
    for(int i = 1; i <= n; i++) {
        if(ai[i] > ai[l])
            l++;
    }
    cout << n - l + 1 << "\n";
    return 0;
}
// 1 2 3 1 2 -> 1 1 2 2 3