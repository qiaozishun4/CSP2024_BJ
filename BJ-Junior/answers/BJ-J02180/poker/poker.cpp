#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128

const int N = 260;
int n, a[N], vis[N], cnt;
char s[N];

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    a['D'] = 0; a['C'] = 1; a['H'] = 2; a['S'] = 3;
    a['A'] = 1; a['T'] = 10; a['J'] = 11; a['Q'] = 12; a['K'] = 13;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s);
        int pos = a[s[0]] * 13 + (isdigit(s[1]) ? s[1] - '0' : a[s[1]]);
        if(!vis[pos]) {
            vis[pos] = 1;
            cnt++;
        }
    }

    printf("%d\n", 52 - cnt);
    return 0;
}
