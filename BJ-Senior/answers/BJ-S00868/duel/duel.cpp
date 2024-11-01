#include<iostream>
#include<cstdio>
using namespace std;

int n, r[100001], cnt[100001], z1, z2, ans = 0, maxr, ky[100001];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> r[i];
        cnt[r[i]]++;
        ky[r[i]]++;
        maxr = max(maxr, r[i]);
    }
    for (z1 = 1;!cnt[z1];z1++);
    z2 = z1 + 1;
    while (true) {
        for (;!cnt[z2] && z2 <= maxr;z2++);
        if (z2 > maxr)
            break;
        if (cnt[z1] <= ky[z2]) {
            ans += cnt[z1];
            ky[z2] -= cnt[z1];
            cnt[z1] = 0;
            z1++;
            for (;!cnt[z1] && z1 <= maxr;z1++);
            if (z2 > maxr)
                break;
            z2 = z1 + 1;
        }
        else {
            ans += cnt[z2];
            cnt[z1] -= ky[z2];
            z2++;
        }

    }
    cout << n - ans;
    return 0;

}
