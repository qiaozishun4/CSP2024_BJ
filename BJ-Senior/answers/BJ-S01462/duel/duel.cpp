// By Pr_159
// Sugar_Pigeon & 159 rp++!
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e5 + 5;

int n, r[N];
vector<pair<int, int> > M;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> r[i];
    }
    sort(r + 1, r + n + 1);
    int sum = 1;
    for(int i = 2; i <= n; ++i) {
        if(r[i] == r[i - 1]) {
            ++sum;
        } else {
            M.push_back({sum, sum});
            sum = 1;
        }
    }
    M.push_back({sum, sum});
    for(int i = 0; i < M.size(); ++i) {
        for(int j = i + 1; j < M.size(); ++j) {
            if(M[j].second > M[i].first) {
                M[j].second -= M[i].first;
                M[i].first = 0;
            } else {
                M[i].first -= M[j].second;
                M[j].second = 0;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < M.size(); ++i) {
        ans += M[i].first;
    }
    cout << ans << '\n';
    return 0;
}
