#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 5, MAXK = 20;
int read(){
    int res = 0, flag = 1;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-')
            flag = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        res = (res << 1) + (res << 3) + (c ^ 48);
    return res * flag;
}
int a_[MAXN], a[MAXN];
int c[MAXN];
int d[20][MAXN];
int b[20][MAXN];
int l2[MAXN];
int val[20][MAXN];
bool flag[20][MAXN];
int x[4];
signed main(){
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    l2[1] = 0;
    for (int i = 2; i < MAXN; i++)
        l2[i] = l2[i / 2] + 1;
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a_[i] = read();
    bool flagA = true;
    for (int i = 1; i <= m; i++)
        c[i] = read(), flagA &= (1 << l2[c[i]]) == c[i];
    int k = 0;
    for (int x = 1; x < n; k++, x *= 2);
    for (int i = 1; i <= k; i++){
        string s;
        cin >> s;
        for (int j = 1; j <= (1 << k - i); j++)
            d[i][j] = s[j - 1] - '0';
    }
    int T = read();
    while (T--){
        x[0] = read(), x[1] = read(), x[2] = read(), x[3] = read();
        for (int i = 1; i <= n; i++)
            a[i] = a_[i] ^ x[i % 4], b[0][i] = i;
        int ans = 0;
        if (flagA){
            for (int i = 1; i <= k; i++){
                for (int j = 1; j <= (1 << k - i); j++){
                    if (d[i][j] == 0)
                        b[i][j] = (a[b[i - 1][j * 2 - 1]] >= i) ? b[i - 1][j * 2 - 1] : b[i - 1][j * 2];
                    else
                        b[i][j] = (a[b[i - 1][j * 2]] >= i) ? b[i - 1][j * 2] : b[i - 1][j * 2 - 1];
                }
            }
            for (int i = 1; i <= m; i++)
                ans ^= i * b[l2[c[i]]][1];
        }else{
            for (int i = 1; i <= m; i++){
                int k1 = l2[c[i]] + ((1 << l2[c[i]]) != c[i]);
                for (int i = 1; i <= (1 << k1); i++)
                    flag[0][i] = (i > c[i]), val[0][i] = a[i];
                for (int i = 1; i <= k; i++){
                    for (int j = 1; j <= (1 << k - i); j++){
                        if (flag[i - 1][j * 2 - 1]){
                            val[i][j] = max(val[i - 1][j * 2 - 1], val[i - 1][j * 2]);
                            b[i][j] = b[i - 1][j * 2 - 1] + b[i - 1][j * 2];
                            flag[i][j] = 1;
                        }else{
                            if (val[i - 1][j * 2 - 1] >= i){
                                b[i][j] = b[i - 1][j * 2 - 1];
                                val[i][j] = val[i - 1][j * 2 - 1];
                                flag[i][j] = 0;
                            }else{
                                b[i][j] = b[i - 1][j * 2];
                                flag[i][j] = 1;
                            }
                        }
                    }
                }
                ans ^= i * b[k1][1];
            }
        }
        cout << ans << endl;
    }
    return 0;
}