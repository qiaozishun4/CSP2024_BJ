#include<bits/stdc++.h>
using namespace std;
// #define int long long
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T --)
    {
        int n;
        cin >> n;
        if (n < 7)
        {
            if (n == 1) cout << -1 << "\n";
            else if (n == 2) cout << 1 << "\n";
            else if (n == 3) cout << 7 << "\n";
            else if (n == 4) cout << 4 << "\n";
            else if (n == 5) cout << 2 << "\n";
            else if (n == 6) cout << 6 << "\n";
        }
        else
        {
            if (n % 7 == 1) cout << 10, n -= 8;
            else if (n % 7 == 2) cout << 1, n -= 2;
            else if (n % 7 == 3) cout << 22, n -= 10;
            else if (n % 7 == 4) cout << 20, n -= 11;
            else if (n % 7 == 5) cout << 2, n -= 5;
            else if (n % 7 == 6) cout << 6, n -= 6;
            for (int i = 1; i <= n / 7; i ++) cout << 8;
            cout << "\n";
        }
    }

    return 0;
}