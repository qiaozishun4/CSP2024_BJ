#include <bits/stdc++.h>

using namespace std;

int h(char n)
{
    if (n == 'D')
        return 0;
    if (n == 'C')
        return 1;
    if (n == 'H')
        return 2;
    if (n == 'S')
        return 3;

}

int z(char n)
{
    if (n == 'A')
        return 0;
    if (n == '2')
        return 1;
    if (n == '3')
        return 2;
    if (n == '4')
        return 3;
    if (n == '5')
        return 4;
    if (n == '6')
        return 5;
    if (n == '7')
        return 6;
    if (n == '8')
        return 7;
    if (n == '9')
        return 8;
    if (n == 'T')
        return 9;
    if (n == 'J')
        return 10;
    if (n == 'Q')
        return 11;
    if (n == 'K')
        return 12;
}

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    int x, y;
    int ans = 0;
    bool p[4][13] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char a[3];
        cin >> a;
        int x = h(a[0]);
        int y = z(a[1]);
        p[x][y] = true;
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
            if (p[i][j])
                ans++;
    cout << 52 - ans << endl;
    return 0;
}
