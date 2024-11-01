#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int cnt = 52;
bool vis[256][256];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    char c1, c2;
    cin >> n;
    for (int i = 1;i <= n;i ++)
    {
        cin >> c1 >> c2;
        if (!vis[c1][c2])
        {
            vis[c1][c2] = 1;
            cnt --;
        }
    }

    cout << cnt;
    return 0;
}
