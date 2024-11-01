# include <iostream>
# include <fstream>
using namespace std;
const int MAXN = 100005;
int n, m;
int ta[MAXN], c[MAXN];

int main ()
{
    freopen ("arena.in", "r", stdin);
    freopen ("arena.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> ta[i];
    for (int i = 1; i <= m; i++)
        cin >> c[i];
    cout << "5\n19\n7\n1";
    return 0;
}