#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

#define MY_TEST

typedef long long ll;

void read(int &rtn) {
    char c = getchar();
    rtn = 0;
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        rtn = (rtn << 3) + (rtn << 1) + c - 48, c = getchar();
}
void read(ll &rtn) {
    char c = getchar();
    rtn = 0LL;
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        rtn = (rtn << 3) + (rtn << 1) + c - 48, c = getchar();
}

const int maxn = 100010;

int n, mons[maxn];

int main() {
    #ifdef MY_TEST
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    #else
    ios::sync_with_stdio(1);
    freopen("duel4.in", "r", stdin);
    freopen("duel4.out", "w", stdout);
    #endif

    cin >> n;
    multiset<pair<int, int>> st, st_atk;
    for (int i = 1; i <= n; ++i) {
        cin >> mons[i];
        st.insert({mons[i], i});
        st_atk.insert({mons[i], i});
    }
    int ans = n;
    while (!st.empty()) {
        multiset<pair<int, int>>::iterator it_pl = st.lower_bound({0, 0});
        it_pl = --st.upper_bound({it_pl->first + 1, 0});
        const pair<int, int> pl = *it_pl;
        multiset<pair<int, int>>::iterator it_sh = st_atk.upper_bound(pl);
        while (it_sh != st_atk.end() && it_sh->first == pl.first) {
            pair<int, int> tmp = *it_sh;
            st_atk.erase(it_sh);
            it_sh = st_atk.upper_bound(tmp);
        }
        if (it_sh != st_atk.end()) {
            const pair<int, int> sh = *it_sh;
            st_atk.erase(it_sh);
            --ans;
        }
        st.erase(it_pl);
    }
    cout << ans << '\n';

    return 0;
}