#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 30;
int n;
int r[N];
int cnt[N];
multiset<int> s;
bool attacked[N], alive[N];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        alive[i] = 1;
        scanf("%d", &r[i]);
        s.insert(r[i]);
    }
    sort(r + 1, r + 1 + n);
    for (int i = 1; i <= n; i++) {
        set<int>::iterator it = s.upper_bound(r[i]);
        if (it != s.end()) {
            s.erase(it);
            alive[i] = 0; 
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (alive[i]) ans++;
    }
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}