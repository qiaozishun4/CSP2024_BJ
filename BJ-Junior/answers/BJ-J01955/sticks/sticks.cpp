#include <bits/stdc++.h>
using namespace std;
#define int long long
const int sti[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const string num[] = {"", "", "1", "7", "4", "2", "6", "8", "10", "18", "22", "20", "28", "68"};

int T, n;

void insert()
{
    cin >> n;
}

void work()
{
    insert();
    if(n == 1)
    {
        cout << -1 << '\n';
        return ;
    }
    if(n % 7 == 0)
    {
        for(int i = 1; i <= n / 7; i++)
            cout << '8';
        cout << '\n';
        return ;
    }
    if(n <= 13)
    {
        cout << num[n] << endl;
        return ;
    }
    string ans = "";
    int nn = n;
    nn -= (n - 7) / 7 * 7;
    cout << num[nn];
    for(int i = 1; i <= (n - 7) / 7; i++)
        cout << '8';
    cout << '\n';
}

signed main()
{
    freopen("sticks.out", "w", stdout);
    freopen("sticks.in", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> T;
    while(T--)
        work();
}