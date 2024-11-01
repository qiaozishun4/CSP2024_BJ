#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string s[62];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    int cnt = 0;
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i++)
        if (i == 1 || s[i] != s[i - 1])
            cnt++;
    cout << 52 - cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
