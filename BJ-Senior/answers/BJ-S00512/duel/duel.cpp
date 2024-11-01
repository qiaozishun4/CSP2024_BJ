#include <bits/stdc++.h>
#define N 100005

using namespace std;
int n, res = 0, a[N], b[N], attack[N];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    for (int i = 0; i < n; i++) b[i] = a[i];
    int tot = unique(b, b+n) - b;
    for (int i = 0; i < n; i++) {
        int nxt = upper_bound(b, b+tot, a[i]) - b; // find the first number greater than a[i] in a
        for (int j = lower_bound(a, a+n, b[nxt]) - a; j < n; j++) {
            if (a[i] < a[j] && (!attack[j])) {
                attack[j] = 1;
                res++;
                break;
            }
        }
    }
    cout << n-res;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
