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

const int N = 2e5;
int cnt[N+5], n;

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    read(n); int a; for (int i = 1;i<=n;i++) read(a), cnt[a]++; int mx = 0;
    for (int i = 1;i<N;i++) checkmax(mx, cnt[i]); printf("%d\n", mx);
    return 0;
}
/*
self check:
1. long long
2. size of array
3. code for testing
4. initializing
*/