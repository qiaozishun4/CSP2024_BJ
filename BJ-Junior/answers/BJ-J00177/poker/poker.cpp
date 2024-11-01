#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool map[500][500];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    memset(map, true, sizeof(map));
    int n, cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char a, b;
        cin >> a >> b;
        cnt += map[a][b];
        map[a][b] = false;
    }
    cout << 52 - cnt;
    return 0;
}
