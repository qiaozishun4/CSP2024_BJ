#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream cin("detect.in");
ofstream cout("detect.out");
int n, m, l, v;
struct car
{
    int d, v, a;
} c[100001];
bool cmp(car a, car b)
{
    return a.d < b.d;
}
struct car_error
{
    int l, r;
};
vector<car_error> ce;
int p[100001];
bool have[1000001];
bool use[1000001];
void solveA()
{
    int ans1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (c[i].v > v)
        {
            for (int j = 1; j <= m; j++)
                if (p[j] >= c[i].d)
                {
                    ans1++;
                    break;
                }
        }
    }
    cout << ans1 << " " << m-1 << endl;
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        cin >> n >> m >> l >> v;
        for (int i = 1; i <= n; i++)
            cin >> c[i].d >> c[i].v >> c[i].a;
        for (int i = 1; i <= m; i++)
            cin >> p[i], have[p[i]] = true;
        sort(c+1, c+n+1, cmp);
        sort(p+1, p+n+1);
        if (c[1].a == 0 && c[n].a == 0) // A
            solveA();
        // else if (c[n].a < 0) // C
        //     solveA();
    }
    return 0;
}