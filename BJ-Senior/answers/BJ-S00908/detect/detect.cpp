#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5 + 5, INF = 1e9;
int t, n, m;
double L, V, p[N];
vector<int> c[N];
//bool b[N];

struct Car
{
    double d, v, a;
    int s;
}a[N];

bool dfs(int x, int y)
{
    if(x == 0)
    {
//        for(int i = 1; i <= m; i++)
//            cout << !b[i] << ' ' ;
//        cout << endl;
//        for(int i = 1; i <= n; i++)
//            cout << a[i].s << ' ';
//        cout << endl;
        for(int i = 1; i <= n; i++)
            if(a[i].s <= 0)
                return false;

        return true;
    }
    for(int i = y; i <= m - x + 1; i++)
    {
        for(int j = 0; j < c[i].size(); j++) a[c[i][j]].s--;
//        b[i] = true;
        bool f = dfs(x - 1, i + 1);
        for(int j = 0; j < c[i].size(); j++) a[c[i][j]].s++;
        if(f) return true;
//        b[i] = false;
    }

    return false;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    cin >> t;
    while(t--)
    {
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i++)
            scanf("%lf%lf%lf", &a[i].d, &a[i].v, &a[i].a);
        for(int i = 1; i <= m; i++)
            scanf("%lf", &p[i]);
        sort(p + 1, p + m + 1);
        int r = 0;
        for(int i = 1; i <= n; i++)
        {
            bool f = false;
            for(int j = lower_bound(p + 1, p + m + 1, a[i].d) - p; j <= m; j++)
            {
                double s = p[j] - a[i].d, v = sqrt(a[i].v * a[i].v + 2 * a[i].a * s);
                if(v > V)
                {
                    f = true;
                    a[i].s++, c[j].push_back(i);
                    if(a[i].a >= 0)
                    {
                        for(j++; j <= m; j++, a[i].s++)
                            c[j].push_back(i);
                        break;
                    }
                }
                else if(a[i].a < 0) break;
            }
            if(f) r++;
            else a[i].s = INF;
//            cout << ' ' << i << ' ' << a[i].s << endl;
        }
//        for(int i = 1; i <= m; i++, cout << endl)
//            for(int j = 0; j < c[i].size(); j++)
//                cout << i << ':' << c[i][j] << ' ';
        int s = 0;
        for(; s <= m; s++)
            if(!dfs(s, 1))
                break;
        cout << r << ' ' << s - 1 <<  endl;
        for(int i = 1; i <= m; i++)
            c[i].clear();
        for(int i = 1; i <= n; i++)
            a[i].s = 0;
    }

    return 0;
}
