#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for (auto i=(a); i <= (b); i++)
#define per(i,a,b) for (auto i=(a); i >= (b); i--)
#define endl '\n'

typedef long long  ll;
typedef unsigned long long  ull;
typedef double lf;

#define N int(1e5+10)

int n;
int a[N];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    rep (i, 1, n) 
    {
        cin >> a[i];
        q.emplace(a[i]);
    }
    sort(a + 1, a + 1 + n);
    int cnt = 0;
    rep (i, 1, n)
    {
        if (a[i] > q.top()) 
        {
            cnt++;
            q.pop();
        }
    }
    cout << n - cnt;
    return 0;
}