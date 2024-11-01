#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int h[N];
int n, x;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        h[x]++;
    }

    sort(h+1, h+N, greater<int>());

    cout << h[1];
    return 0;
}