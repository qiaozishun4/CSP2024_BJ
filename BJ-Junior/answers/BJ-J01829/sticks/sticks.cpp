#include<bits/stdc++.h>
using namespace std;
int n, q;
int special[10] = {-1, -1, 1, 7, 4, 2, 6, 8};
int start[10] = {88, 10, 18, 22, 20, 28, 68};
void solve()
{
    if(n >= 8)
    {
        cout << start[n%7];
        int num = (n - 1) / 7 - 1;
        for(int i = 0; i < num; i++) cout << 8;
    }
    else cout << special[n];
    cout << '\n';
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> n;
        solve();
    }
    return 0;
}
