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
int n, m, l, v_max;
vector<PII> seg, cover;
int sum[N], pos[N], top;
PII val[N];

inline void Push(int Left, int Right){
    checkmin(Right, l); if (Left<=Right) seg.pb({Left, Right});// printf("%d %d\n", Left, Right);
}

inline int Sum(int l, int r){
    int ans = sum[r]; if (l) ans -= sum[l-1]; return ans;
}

inline void solve(){
    read(n, m, l, v_max); int d, v, a; seg.clear(), cover.clear();
    for (int i = 1;i<=n;i++){
        read(d, v, a);
        if (a>0){
            if (v<=v_max) Push((v_max*v_max - v*v)/2/a + d + 1, l);
            else Push(d, l);
        }
        else if (a == 0){
            if (v>v_max) Push(d, l);
        }
        else{
            if (v>v_max) Push(d, d+(v*v - v_max*v_max - 1)/(-2*a));
        }
    }
    memset(sum, 0, sizeof(sum));
    for (int i = 1;i<=m;i++) read(pos[i]), sum[pos[i]]++;
    for (int i = 1;i<N;i++) sum[i] += sum[i-1];
    for (auto x: seg){
        if (Sum(x.first, x.second)) cover.pb(x);
    }
    int ans = cover.size(); printf("%d ", ans);

    top = 0; int id = 0, cnt = 0;
    sort(cover.begin(), cover.end());
    for (auto x: cover){
        while (top && x.second<=val[top].second) top--;
        val[++top] = x;
    }
    for (int i = 1;i<=top;i++){
        if (val[i].first<=pos[id]) continue; cnt++;
        while (id<m && pos[id+1]<=val[i].second) id++;
    }
    printf("%d\n", m-cnt);
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
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