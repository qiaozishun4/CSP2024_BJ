#include<bits/stdc++.h>
#define pb push_back
#define popcnt __builtin_popcountll
#define debug printf("Passed line %d\n", __LINE__)

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

template<typename T> inline void read(T &x){
    bool F = 0; char c = getchar(); x = 0;
    for (;!isdigit(c);c = getchar()) if (c == '-') F = 1;
    for (;isdigit(c);c = getchar()) x = x*10+(c^48);
    if (F) x = -x;
}

template<typename T1, typename ...T2> inline void read(T1 &x, T2 &...y){read(x), read(y...);}

template<typename T> inline void checkmax(T &x, const T &y){if (x<y) x = y;}

template<typename T> inline void checkmin(T &x, const T &y){if (x>y) x = y;}

const int N = 1e6+5;
ll dp[N], mx, delta;
int a[N], n;

inline void solve(){
    read(n); for (int i = 1;i<=n;i++) read(a[i]); memset(dp, 200, sizeof(dp)); mx = delta = 0;
    dp[0] = 0;
    for (int i = 2;i<=n;i++){
        if (a[i] == a[i-1]){
            delta += a[i];
            checkmax(dp[a[i-1]], max(mx, dp[a[i]]+a[i]) - a[i]);
        }
        else{
            checkmax(dp[a[i-1]], max(mx, dp[a[i]]+a[i]));
            checkmax(mx, dp[a[i-1]]);
        }
    }
    printf("%lld\n", mx+delta);
}

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t; read(t); while (t--) solve();
    return 0;
}
/*
self check:
1. long long
2. size of array
3. code for testing
4. initializing
*/