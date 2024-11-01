#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int MAXN = 300010;
const int INF  = 0x3f3f3f3f;
const ll INFL  = 0x3f3f3f3f3f3f3f3f;
const double MMIN = 1e-6;
#define i128 __int128
#define pii pair<int, int>
#define mkp(A, B) make_pair(A, B)
#define F first
#define S second

int T, n, ai[MAXN];

void subtask1()
{
    ll ans = 0;
    for(int i = 0; i <= (1 << n) - 1; i++) {
        int lsb = 0, lsr = 0; ll tmp = 0;
        for(int j = 1; j <= n; j++) {
            if(i & (1 << (j - 1))) { // red
                if(ai[j] == ai[lsr]) 
                    tmp += ai[j];
                lsr = j;
            }
            else {
                if(ai[j] == ai[lsb]) 
                    tmp += ai[j];
                lsb = j;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << "\n";
}

int di[2150][2150];
void subtask2()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) di[i][j] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) 
            di[j][i] = max(di[j][i], di[j][i - 1] + (ai[i - 1] == ai[i] ? ai[i] : 0));
        for(int j = 1; j <= i - 1; j++) {
            di[i][i] = max(di[i][i], di[j][i - 1] + (ai[j - 1] == ai[i] ? ai[i] : 0));
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(di[i][n], ans);
    }
    cout << ans << "\n";
}
void work()
{
    // init();
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> ai[i];
    if(n <= 15) {
        subtask1();
        return;
    }
    else if(n <= 2000) {
        subtask2();
        return;
    }
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        work();
    }
    return 0;
}
// 1 2 3 1 2 -> 1 1 2 2 3