#include <cstdio>
#include <iostream>
using namespace std;
bool f[5][15];
int get1(char a)
{
    if (a == 'D') return 1;
    if (a == 'C') return 2;
    if (a == 'H') return 3;
    return 4;
}
int get2(char b)
{
    if ('2' <= b && b <= '9') return b - '0';
    if (b == 'A') return 1;
    if (b == 'T') return 10;
    if (b == 'J') return 11;
    if (b == 'Q') return 12;
    return 13;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans = 0;
    cin >> n;
    while (n--)
    {
        char a,b;
        cin >> a >> b;
        f[get1(a)][get2(b)] = 1;
    }
    for (int i = 1;i <= 4;i++)
    {
        for (int j = 1;j <= 13;j++)
        {
            if (!f[i][j]) ans++;
        }
    }
    cout << ans;
    return 0;
}