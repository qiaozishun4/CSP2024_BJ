#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 5;
ll T, nn;
ll aa[maxn], zt[maxn];
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> nn;
        for (int i = 1; i <= nn; i++) {
            cin >> aa[i];
        }
        ll ans = -1e9;
        if (nn == 1) {
            ans = 0;
        } else if (nn == 2) {
            for (int a = 1; a <= 2; a++) {
                for (int b = 1; b <= 2; b++) {
                    ll cnt = 0;
                    ll lr = 0, lb = 0;
                    zt[1] = a;
                    zt[2] = b;
                    for (int z = 1; z <= 2; z++) {
                        if (zt[z] == 1) {
                            if (aa[lr] == aa[z]) {
                                cnt += aa[z];
                            }
                            lr = z;
                        } else if (zt[z] == 2) {
                            if (aa[lb] == aa[z]) {
                                cnt += aa[z];
                            }
                            lb = z;
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        } else if (nn == 3) {
            for (int a = 1; a <= 2; a++) {
                for (int b = 1; b <= 2; b++) {
                    for (int c = 1; c <= 2; c++) {
                        ll cnt = 0;
                        ll lr = 0, lb = 0;
                        zt[1] = a;
                        zt[2] = b;
                        zt[3] = c;
                        for (int z = 1; z <= 3; z++) {
                            if (zt[z] == 1) {
                                if (aa[lr] == aa[z]) {
                                    cnt += aa[z];
                                }
                                lr = z;
                            } else if (zt[z] == 2) {
                                if (aa[lb] == aa[z]) {
                                    cnt += aa[z];
                                }
                                lb = z;
                            }
                        }
                        ans = max(ans, cnt);
                    }
                }
            }
        } else if (nn == 4) {
            for (int a = 1; a <= 2; a++) {
                for (int b = 1; b <= 2; b++) {
                    for (int c = 1; c <= 2; c++) {
                        for (int d = 1; d <= 2; d++) {
                            ll cnt = 0;
                            ll lr = 0, lb = 0;
                            zt[1] = a;
                            zt[2] = b;
                            zt[3] = c;
                            zt[4] = d;
                            for (int z = 1; z <= 4; z++) {
                                if (zt[z] == 1) {
                                    if (aa[lr] == aa[z]) {
                                        cnt += aa[z];
                                    }
                                    lr = z;
                                } else if (zt[z] == 2) {
                                    if (aa[lb] == aa[z]) {
                                        cnt += aa[z];
                                    }
                                    lb = z;
                                }
                            }
                            ans = max(ans, cnt);
                        }
                    }
                }
            }
        } else if (nn == 5) {
            for (int a = 1; a <= 2; a++) {
                for (int b = 1; b <= 2; b++) {
                    for (int c = 1; c <= 2; c++) {
                        for (int d = 1; d <= 2; d++) {
                            for (int e = 1; e <= 2; e++) {
                                ll cnt = 0;
                                ll lr = 0, lb = 0;
                                zt[1] = a;
                                zt[2] = b;
                                zt[3] = c;
                                zt[4] = d;
                                zt[5] = e;
                                for (int z = 1; z <= 5; z++) {
                                    if (zt[z] == 1) {
                                        if (aa[lr] == aa[z]) {
                                            cnt += aa[z];
                                        }
                                        lr = z;
                                    } else if (zt[z] == 2) {
                                        if (aa[lb] == aa[z]) {
                                            cnt += aa[z];
                                        }
                                        lb = z;
                                    }
                                }
                                ans = max(ans, cnt);
                            }
                        }
                    }
                }
            }
        } else if (nn == 6) {
            for (int a = 1; a <= 2; a++) {
                for (int b = 1; b <= 2; b++) {
                    for (int c = 1; c <= 2; c++) {
                        for (int d = 1; d <= 2; d++) {
                            for (int e = 1; e <= 2; e++) {
                                for (int f = 1; f <= 2; f++) {
                                    ll cnt = 0;
                                    ll lr = 0, lb = 0;
                                    zt[1] = a;
                                    zt[2] = b;
                                    zt[3] = c;
                                    zt[4] = d;
                                    zt[5] = e;
                                    zt[6] = f;
                                    for (int z = 1; z <= 6; z++) {
                                        if (zt[z] == 1) {
                                            if (aa[lr] == aa[z]) {
                                                cnt += aa[z];
                                            }
                                            lr = z;
                                        } else if (zt[z] == 2) {
                                            if (aa[lb] == aa[z]) {
                                                cnt += aa[z];
                                            }
                                            lb = z;
                                        }
                                    }
                                    ans = max(ans, cnt);
                                }
                            }
                        }
                    }
                }
            }
        } else if (nn == 7) {
            for (int a = 1; a <= 2; a++) {
                for (int b = 1; b <= 2; b++) {
                    for (int c = 1; c <= 2; c++) {
                        for (int d = 1; d <= 2; d++) {
                            for (int e = 1; e <= 2; e++) {
                                for (int f = 1; f <= 2; f++) {
                                    for (int g = 1; g <= 2; g++) {
                                        ll cnt = 0;
                                        ll lr = 0, lb = 0;
                                        zt[1] = a;
                                        zt[2] = b;
                                        zt[3] = c;
                                        zt[4] = d;
                                        zt[5] = e;
                                        zt[6] = f;
                                        zt[7] = g;
                                        for (int z = 1; z <= 7; z++) {
                                            if (zt[z] == 1) {
                                                if (aa[lr] == aa[z]) {
                                                    cnt += aa[z];
                                                }
                                                lr = z;
                                            } else if (zt[z] == 2) {
                                                if (aa[lb] == aa[z]) {
                                                    cnt += aa[z];
                                                }
                                                lb = z;
                                            }
                                        }
                                        ans = max(ans, cnt);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (nn == 8) {
            for (int a = 1; a <= 2; a++) {
                for (int b = 1; b <= 2; b++) {
                    for (int c = 1; c <= 2; c++) {
                        for (int d = 1; d <= 2; d++) {
                            for (int e = 1; e <= 2; e++) {
                                for (int f = 1; f <= 2; f++) {
                                    for (int g = 1; g <= 2; g++) {
                                        for (int h = 1; h <= 2; h++) {
                                            ll cnt = 0;
                                            ll lr = 0, lb = 0;
                                            zt[1] = a;
                                            zt[2] = b;
                                            zt[3] = c;
                                            zt[4] = d;
                                            zt[5] = e;
                                            zt[6] = f;
                                            zt[7] = g;
                                            zt[8] = h;
                                            for (int z = 1; z <= 8; z++) {
                                                if (zt[z] == 1) {
                                                    if (aa[lr] == aa[z]) {
                                                        cnt += aa[z];
                                                    }
                                                    lr = z;
                                                } else if (zt[z] == 2) {
                                                    if (aa[lb] == aa[z]) {
                                                        cnt += aa[z];
                                                    }
                                                    lb = z;
                                                }
                                            }
                                            ans = max(ans, cnt);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (nn == 9) {
            for (int a = 1; a <= 2; a++) {
                for (int b = 1; b <= 2; b++) {
                    for (int c = 1; c <= 2; c++) {
                        for (int d = 1; d <= 2; d++) {
                            for (int e = 1; e <= 2; e++) {
                                for (int f = 1; f <= 2; f++) {
                                    for (int g = 1; g <= 2; g++) {
                                        for (int h = 1; h <= 2; h++) {
                                            for (int i = 1; i <= 2; i++) {
                                                ll cnt = 0;
                                                ll lr = 0, lb = 0;
                                                zt[1] = a;
                                                zt[2] = b;
                                                zt[3] = c;
                                                zt[4] = d;
                                                zt[5] = e;
                                                zt[6] = f;
                                                zt[7] = g;
                                                zt[8] = h;
                                                zt[9] = i;
                                                for (int z = 1; z <= 9; z++) {
                                                    if (zt[z] == 1) {
                                                        if (aa[lr] == aa[z]) {
                                                            cnt += aa[z];
                                                        }
                                                        lr = z;
                                                    } else if (zt[z] == 2) {
                                                        if (aa[lb] == aa[z]) {
                                                            cnt += aa[z];
                                                        }
                                                        lb = z;
                                                    }
                                                }
                                                ans = max(ans, cnt);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (nn == 10) {
            for (int a = 1; a <= 2; a++) {
                for (int b = 1; b <= 2; b++) {
                    for (int c = 1; c <= 2; c++) {
                        for (int d = 1; d <= 2; d++) {
                            for (int e = 1; e <= 2; e++) {
                                for (int f = 1; f <= 2; f++) {
                                    for (int g = 1; g <= 2; g++) {
                                        for (int h = 1; h <= 2; h++) {
                                            for (int i = 1; i <= 2; i++) {
                                                for (int j = 1; j <= 2; j++) {
                                                    ll cnt = 0;
                                                    ll lr = 0, lb = 0;
                                                    zt[1] = a;
                                                    zt[2] = b;
                                                    zt[3] = c;
                                                    zt[4] = d;
                                                    zt[5] = e;
                                                    zt[6] = f;
                                                    zt[7] = g;
                                                    zt[8] = h;
                                                    zt[9] = i;
                                                    zt[10] = j;
                                                    for (int z = 1; z <= 10; z++) {
                                                        if (zt[z] == 1) {
                                                            if (aa[lr] == aa[z]) {
                                                                cnt += aa[z];
                                                            }
                                                            lr = z;
                                                        } else if (zt[z] == 2) {
                                                            if (aa[lb] == aa[z]) {
                                                                cnt += aa[z];
                                                            }
                                                            lb = z;
                                                        }
                                                    }
                                                    ans = max(ans, cnt);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (nn == 11) {
            for (int a = 1; a <= 2; a++) {
                for (int b = 1; b <= 2; b++) {
                    for (int c = 1; c <= 2; c++) {
                        for (int d = 1; d <= 2; d++) {
                            for (int e = 1; e <= 2; e++) {
                                for (int f = 1; f <= 2; f++) {
                                    for (int g = 1; g <= 2; g++) {
                                        for (int h = 1; h <= 2; h++) {
                                            for (int i = 1; i <= 2; i++) {
                                                for (int j = 1; j <= 2; j++) {
                                                    for (int k = 1; k <= 2; k++) {
                                                        ll cnt = 0;
                                                        ll lr = 0, lb = 0;
                                                        zt[1] = a;
                                                        zt[2] = b;
                                                        zt[3] = c;
                                                        zt[4] = d;
                                                        zt[5] = e;
                                                        zt[6] = f;
                                                        zt[7] = g;
                                                        zt[8] = h;
                                                        zt[9] = i;
                                                        zt[10] = j;
                                                        zt[11] = k;
                                                        for (int z = 1; z <= 11; z++) {
                                                            if (zt[z] == 1) {
                                                                if (aa[lr] == aa[z]) {
                                                                    cnt += aa[z];
                                                                }
                                                                lr = z;
                                                            } else if (zt[z] == 2) {
                                                                if (aa[lb] == aa[z]) {
                                                                    cnt += aa[z];
                                                                }
                                                                lb = z;
                                                            }
                                                        }
                                                        ans = max(ans, cnt);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (nn == 12) {
            for (int a = 1; a <= 2; a++) {
                for (int b = 1; b <= 2; b++) {
                    for (int c = 1; c <= 2; c++) {
                        for (int d = 1; d <= 2; d++) {
                            for (int e = 1; e <= 2; e++) {
                                for (int f = 1; f <= 2; f++) {
                                    for (int g = 1; g <= 2; g++) {
                                        for (int h = 1; h <= 2; h++) {
                                            for (int i = 1; i <= 2; i++) {
                                                for (int j = 1; j <= 2; j++) {
                                                    for (int k = 1; k <= 2; k++) {
                                                        for (int l = 1; l <= 2; l++) {
                                                            ll cnt = 0;
                                                            ll lr = 0, lb = 0;
                                                            zt[1] = a;
                                                            zt[2] = b;
                                                            zt[3] = c;
                                                            zt[4] = d;
                                                            zt[5] = e;
                                                            zt[6] = f;
                                                            zt[7] = g;
                                                            zt[8] = h;
                                                            zt[9] = i;
                                                            zt[10] = j;
                                                            zt[11] = k;
                                                            zt[12] = l;
                                                            for (int z = 1; z <= 12; z++) {
                                                                if (zt[z] == 1) {
                                                                    if (aa[lr] == aa[z]) {
                                                                        cnt += aa[z];
                                                                    }
                                                                    lr = z;
                                                                } else if (zt[z] == 2) {
                                                                    if (aa[lb] == aa[z]) {
                                                                        cnt += aa[z];
                                                                    }
                                                                    lb = z;
                                                                }
                                                            }
                                                            ans = max(ans, cnt);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (nn == 13) {
            for (int a = 1; a <= 2; a++) {
                for (int b = 1; b <= 2; b++) {
                    for (int c = 1; c <= 2; c++) {
                        for (int d = 1; d <= 2; d++) {
                            for (int e = 1; e <= 2; e++) {
                                for (int f = 1; f <= 2; f++) {
                                    for (int g = 1; g <= 2; g++) {
                                        for (int h = 1; h <= 2; h++) {
                                            for (int i = 1; i <= 2; i++) {
                                                for (int j = 1; j <= 2; j++) {
                                                    for (int k = 1; k <= 2; k++) {
                                                        for (int l = 1; l <= 2; l++) {
                                                            for (int m = 1; m <= 2; m++) {
                                                                ll cnt = 0;
                                                                ll lr = 0, lb = 0;
                                                                zt[1] = a;
                                                                zt[2] = b;
                                                                zt[3] = c;
                                                                zt[4] = d;
                                                                zt[5] = e;
                                                                zt[6] = f;
                                                                zt[7] = g;
                                                                zt[8] = h;
                                                                zt[9] = i;
                                                                zt[10] = j;
                                                                zt[11] = k;
                                                                zt[12] = l;
                                                                zt[13] = m;
                                                                for (int z = 1; z <= 13; z++) {
                                                                    if (zt[z] == 1) {
                                                                        if (aa[lr] == aa[z]) {
                                                                            cnt += aa[z];
                                                                        }
                                                                        lr = z;
                                                                    } else if (zt[z] == 2) {
                                                                        if (aa[lb] == aa[z]) {
                                                                            cnt += aa[z];
                                                                        }
                                                                        lb = z;
                                                                    }
                                                                }
                                                                ans = max(ans, cnt);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (nn == 14) {
            for (int a = 1; a <= 2; a++) {
                for (int b = 1; b <= 2; b++) {
                    for (int c = 1; c <= 2; c++) {
                        for (int d = 1; d <= 2; d++) {
                            for (int e = 1; e <= 2; e++) {
                                for (int f = 1; f <= 2; f++) {
                                    for (int g = 1; g <= 2; g++) {
                                        for (int h = 1; h <= 2; h++) {
                                            for (int i = 1; i <= 2; i++) {
                                                for (int j = 1; j <= 2; j++) {
                                                    for (int k = 1; k <= 2; k++) {
                                                        for (int l = 1; l <= 2; l++) {
                                                            for (int m = 1; m <= 2; m++) {
                                                                for (int n = 1; n <= 2; n++) {
                                                                    ll cnt = 0;
                                                                    ll lr = 0, lb = 0;
                                                                    zt[1] = a;
                                                                    zt[2] = b;
                                                                    zt[3] = c;
                                                                    zt[4] = d;
                                                                    zt[5] = e;
                                                                    zt[6] = f;
                                                                    zt[7] = g;
                                                                    zt[8] = h;
                                                                    zt[9] = i;
                                                                    zt[10] = j;
                                                                    zt[11] = k;
                                                                    zt[12] = l;
                                                                    zt[13] = m;
                                                                    zt[14] = n;
                                                                    for (int z = 1; z <= 14; z++) {
                                                                        if (zt[z] == 1) {
                                                                            if (aa[lr] == aa[z]) {
                                                                                cnt += aa[z];
                                                                            }
                                                                            lr = z;
                                                                        } else if (zt[z] == 2) {
                                                                            if (aa[lb] == aa[z]) {
                                                                                cnt += aa[z];
                                                                            }
                                                                            lb = z;
                                                                        }
                                                                    }
                                                                    ans = max(ans, cnt);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (nn == 15) {
            for (int a = 1; a <= 2; a++) {
                for (int b = 1; b <= 2; b++) {
                    for (int c = 1; c <= 2; c++) {
                        for (int d = 1; d <= 2; d++) {
                            for (int e = 1; e <= 2; e++) {
                                for (int f = 1; f <= 2; f++) {
                                    for (int g = 1; g <= 2; g++) {
                                        for (int h = 1; h <= 2; h++) {
                                            for (int i = 1; i <= 2; i++) {
                                                for (int j = 1; j <= 2; j++) {
                                                    for (int k = 1; k <= 2; k++) {
                                                        for (int l = 1; l <= 2; l++) {
                                                            for (int m = 1; m <= 2; m++) {
                                                                for (int n = 1; n <= 2; n++) {
                                                                    for (int o = 1; o <= 2; o++) {
                                                                        ll cnt = 0;
                                                                        ll lr = 0, lb = 0;
                                                                        zt[1] = a;
                                                                        zt[2] = b;
                                                                        zt[3] = c;
                                                                        zt[4] = d;
                                                                        zt[5] = e;
                                                                        zt[6] = f;
                                                                        zt[7] = g;
                                                                        zt[8] = h;
                                                                        zt[9] = i;
                                                                        zt[10] = j;
                                                                        zt[11] = k;
                                                                        zt[12] = l;
                                                                        zt[13] = m;
                                                                        zt[14] = n;
                                                                        zt[15] = o;
                                                                        for (int z = 1; z <= 15; z++) {
                                                                            if (zt[z] == 1) {
                                                                                if (aa[lr] == aa[z]) {
                                                                                    cnt += aa[z];
                                                                                }
                                                                                lr = z;
                                                                            } else if (zt[z] == 2) {
                                                                                if (aa[lb] == aa[z]) {
                                                                                    cnt += aa[z];
                                                                                }
                                                                                lb = z;
                                                                            }
                                                                        }
                                                                        ans = max(ans, cnt);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
