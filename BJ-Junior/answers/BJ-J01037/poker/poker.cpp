#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, cnt = 0;
    string s;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        if(m[s]) cnt++;
        else m[s] = 1;
    }
    cout << 52 - (n - cnt);

    return 0;
}

