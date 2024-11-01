#include<bits/stdc++.h>

using namespace std;
long long n;
const int N = 1e5 + 10;
long long r;
long long cnt[N];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    long long maxn = -1;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> r;
        cnt[r] ++ ;
        maxn = max(maxn, cnt[r]);
    }
    cout << maxn << endl;
    return 0;
}
