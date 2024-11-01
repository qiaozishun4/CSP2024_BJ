

#include <cstdio>
#define ll long long

using namespace std;

int INF = 2147483647;
int N;
int M;
int K;
int tk;
int tA[100009];
int A[100009];
int C[100009];
int D[19][300009];
int T;
int X[4];
bool va[300009];
int rd[300009];
int L[300009];
int R[300009];
int mn[300009];
int mx[300009];
ll wc[300009];
ll ans[300009];
ll res;

void Build (int x, int l, int r, int k, int d) {
    L[x] = l, R[x] = r, rd[x] = K - k;
    if (D[rd[x]][d]) va[x << 1 | 1] = true;
    else va[x << 1] = true;
    int mid = l + r >> 1;
    if (k < K) Build(x << 1, l, mid, k + 1, d << 1), Build(x << 1 | 1, mid + 1, r, k + 1, d << 1 | 1);
}

void Upd (int x) {
    if (L[x] == R[x]) {
        ans[x] = wc[x] = L[x], mn[x] = mx[x] = A[L[x]];
        return;
    }
    Upd(x << 1), Upd(x << 1 | 1);
    if (va[x << 1]) {
        if (A[wc[x << 1]] >= rd[x]) wc[x] = wc[x << 1];
        else wc[x] = wc[x << 1 | 1];
    }
    else {
        if (A[wc[x << 1 | 1]] >= rd[x]) wc[x] = wc[x << 1 | 1];
        else wc[x] = wc[x << 1];
    }
    ans[x] = wc[x];
    mn[x] = mx[x] = A[wc[x]];
}

int Min (int a, int b) {
    return a < b ? a : b;
}

int Max (int a, int b) {
    return a > b ? a : b;
}

void Get_Ans (int x, int l, int r) {
    if (l > r) return;
    if (L[x] >= l && R[x] <= r) {
        ans[x] = ((ll)(L[x] + R[x])) * ((ll)(R[x] - L[x] + 1ll)) / 2ll;
        mn[x] = 0, mx[x] = INF;
        return;
    }
    int mid = L[x] + R[x] >> 1;
    if (l <= mid) Get_Ans(x << 1, l, r);
    if (mid < r) Get_Ans(x << 1 | 1, l, r);
    int mnx = 1e9;
    int mxx = -1e9;
    ll ansx = 0;
    if (va[x << 1]) {
        if (mn[x << 1] < rd[x]) ansx += ans[x << 1 | 1], mnx = Min(mnx, mn[x << 1 | 1]), mxx = Max(mxx, mx[x << 1 | 1]);
        if (mx[x << 1] >= rd[x]) ansx += ans[x << 1], mnx = Min(mnx, mn[x << 1]), mxx = Max(mxx, mx[x << 1]);
    }
    else if (va[x << 1 | 1]) {
        if (mn[x << 1 | 1] < rd[x]) ansx += ans[x << 1], mnx = Min(mnx, mn[x << 1]), mxx = Max(mxx, mx[x << 1]);
        if (mx[x << 1 | 1] >= rd[x]) ansx += ans[x << 1 | 1], mnx = Min(mnx, mn[x << 1 | 1]), mxx = Max(mxx, mx[x << 1 | 1]);
    }
    mn[x] = mnx, mx[x] = mxx, ans[x] = ansx;
}

void Clear (int x, int l, int r) {
    if (l > r) return;
    if (L[x] >= l && R[x] <= r) {
        ans[x] = wc[x];
        mn[x] = mx[x] = A[wc[x]];
        return;
    }
    int mid = L[x] + R[x] >> 1;
    if (l <= mid) Clear(x << 1, l, r);
    if (mid < r) Clear(x << 1 | 1, l, r);
    ans[x] = wc[x];
    mn[x] = mx[x] = A[wc[x]];
}

int main () {
    char s[100009];
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) scanf("%d", &tA[i]);
    for (int i = 1; i <= M; i++) scanf("%d", &C[i]);
    for (int i = 0; i < 19; i++)
        if ((1 << i) >= N) {
            K = i;
            break;
        }
    for (int i = 1; i <= K; i++) {
        scanf("%s", s);
        for (int j = 0; j < (1 << (K - i)); j++) D[i][j] = s[j] - '0';
    }
    Build(1, 1, 1 << K, 0, 0);
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 4; i++) scanf("%d", &X[i]);
        for (int i = 1; i <= N; i++) A[i] = (tA[i] ^ X[i % 4]);
        Upd(1);
        res = 0;
        for (int i = 1; i <= M; i++) {
            for (int j = 0; j < 19; j++)
                if ((1 << j) >= C[i]) {
                    tk = j;
                    break;
                }
            Get_Ans(1 << (K - tk), C[i] + 1, 1 << tk);
            res ^= ((ll)(i) * ans[1 << (K - tk)]);
            Clear(1 << (K - tk), C[i] + 1, 1 << tk);
        }
        printf("%lld\n", res);
    }
    fclose(stdin), fclose(stdout);
    return 0;
}