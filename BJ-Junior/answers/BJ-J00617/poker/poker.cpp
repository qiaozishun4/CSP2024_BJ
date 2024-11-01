#include <bits/stdc++.h>
using namespace std;

set<string> s; string st;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> st;
        s.insert(st);
    }
    cout << 52 - s.size();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
