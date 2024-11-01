#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n;
bool flag[5][15];
int get1(char a)
{
    if(a == 'D') return 1;
    if(a == 'C') return 2;
    if(a == 'H') return 3;
    if(a == 'S') return 4;
}
int get2(char b)
{
    if(b == 'A') return 1;
    if(b == 'T') return 10;
    if(b == 'J') return 11;
    if(b == 'Q') return 12;
    if(b == 'K') return 13;
    return b - '0';
}
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    //freopen("//home//csp-j//poker1.in", "r", stdin);
    memset(flag, 0, sizeof(flag));
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        char a, b;
        cin >> a >> b;
        int x = get1(a), y = get2(b);
        flag[x][y] = true;
    }
    int ans = 0;
    for(int i = 1; i <= 4; i ++)
        for(int j = 1; j <= 13; j++)
            if(!flag[i][j]) ans++;
    cout << ans << endl;
    return 0;
}
