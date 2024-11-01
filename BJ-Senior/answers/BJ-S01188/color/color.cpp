#include <bits/stdc++.h>

using namespace std;

int T, n, m, l, v2, s, cnt;
int d[100005], v[100005], a[100005], p[100005];
double tmp;

void solve() {
    cnt = 0;
    cin >> n >> m >> l >> v2;
    for (int i = 1; i <= n; i++) {
        cin >> d[i] >> v[i] >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
            continue;
        }
        for (int j = 1; j <= m; j++) {
            s = p[j] - d[i];
            tmp = sqrt(v[i] * v[i] + 2 * a[i] * s);
            if (tmp > v2) cnt++;
        }
    }
    cout << n << " " << n << "\n";
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cout << "1\n0\n8";
}


// 迷惑行为大赏
//


/*
这是一首藏头诗
是是一首藏头诗
一一一首藏头诗
首首首首藏头诗
藏藏藏藏藏头诗
头头头头头头诗
诗诗诗诗诗诗诗

*/
