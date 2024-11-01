#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NR = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n, m, a0[NR], c[NR], a[NR];
int pw[20], K;
char d[20][20];
int logn[NR];
bool B = true;
int q[NR], cnt = 0;
bool flag[NR];
void dfs(int r, int c, int k){
    if (r > k){
        flag[q[1]] = true;
        return;
    }
}
void test(){
    int x[4] = {};
    for (int i = 0; i <= 3; i++){
        cin >> x[i];
    }
    memset(a, 0x3f, sizeof a);
    for (int i = 1; i <= n; i++){
        a[i] = (a0[i] ^ x[i % 4]);
    }
    if (n <= 8){
        int ans = 0;
        for (int i = 1; i <= m; i++){
            int k = logn[c[i]];
            for (int j = 1; j <= pw[k]; j++){
                flag[j] = false;
            }
            dfs(1, 1, k);
            int sum = 0;
            for (int j = 1; j <= pw[k]; j++){
                if (flag[j]) sum += j;
            }
            ans ^= (i * sum);
        }
        cout << ans << endl;
        return;
    }
}
int main(){
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> n >> m;
    pw[0] = 1;
    for (int i = 1; i <= 17; i++){
        pw[i] = pw[i - 1] * 2;
        if (pw[i] >= n){
            K = i;
            break;
        }
    }
    for (int i = 1, j = 1; i <= n; i++){
        if (i < pw[j]) logn[i] = j;
        else{
            logn[i] = j;
            j++;
        }
    }
    for (int i = 1; i <= n; i++){
        cin >> a0[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> c[i];
    }
    for (int i = 1; i <= K; i++){
        for (int j = 1; j <= pw[K - i]; j++){
            cin >> d[i][j];
            B &= (d[i][j] == '0');
        }
    }
    cin >> T;
    while (T--){
        test();
    }
    return 0;
}
