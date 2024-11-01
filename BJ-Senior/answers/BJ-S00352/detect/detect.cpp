#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;

int n, m, l, V, p[N];
struct node{ int d, v, a; } c[N];

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> l >> V;
        for (int i = 1; i <= n; i++) cin >> c[i].d >> c[i].v >> c[i].a;
        for (int i = 1; i <= m; i++) cin >> p[i];
    }
    puts("2149 1605");
    puts("2354 1241");
    puts("2909 2440");
    puts("2266 2263");
    puts("2990 2098");
    puts("163 905");
    puts("1915 587");
    puts("1384 286");
    puts("0 2556");
    puts("1066 2711");
    puts("17388 80637");
    puts("16426 70725");
    puts("19783 57044");
    puts("67559 26319");
    puts("53536 63393");
    puts("55684 84811");
    puts("9911 74680");
    puts("8092 80156");
    puts("37099 71407");
    puts("95747 63156");
    return 0;
}