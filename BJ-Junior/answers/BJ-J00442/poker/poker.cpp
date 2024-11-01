#include <bits/stdc++.h>
using namespace std;

int n;
set<int> s;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        char card[2];
        cin >> card;
        int tmp = card[0] * 10000 + card[1];
        s.insert(tmp);
    }
    cout << (52 - s.size()) << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
