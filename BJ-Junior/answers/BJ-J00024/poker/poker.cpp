#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

string a[60];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int pos = unique(a + 1, a + n + 1) - a - 1;
    cout << 52 - pos << endl;
    return 0;
}
