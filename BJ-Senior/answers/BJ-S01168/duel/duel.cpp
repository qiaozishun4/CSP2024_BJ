#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, r[N];
bool f[N];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> r[i];
    sort(r + 1, r + n + 1);
    for(int i = 1; i <= n; i++)
        f[i] = 1;
    int p = 1;
    for(int i = 2; i <= n; i++)
        if(r[i] > r[p])
            f[p++] = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(f[i])
            cnt++;
    cout << cnt << endl;
    return 0;
}
