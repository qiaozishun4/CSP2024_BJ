#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 5, MAXV = 1e6 + 5;
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
int a[MAXN];
int f1[MAXV], f2[MAXV];
signed main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T = read();
    while (T--){
        int n = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i < MAXV; i++)
            f1[i] = f2[i] = -1e18;
        f1[a[1]] = f2[a[1]] = 0;
        int add1 = 0, add2 = 0;
        int ans1 = 0, ans2 = 0;
        for (int i = 2; i <= n; i++){
            int num1 = max(ans1, f1[a[i]] + a[i]) + add1;
            int num2 = max(ans2, f2[a[i]] + a[i]) + add2;
            int add = (a[i] == a[i - 1]) * a[i];
            f1[a[i - 1]] = max(f1[a[i - 1]], num2 - add - add1);
            ans1 = max(ans1, num2 - add - add1);
            f2[a[i - 1]] = max(f2[a[i - 1]], num1 - add - add2);
            ans2 = max(ans2, num1 - add - add2);
            add1 += add, add2 += add;
        }
        cout << max(ans1 + add1, ans2 + add2) << endl;
    }
    return 0;
}