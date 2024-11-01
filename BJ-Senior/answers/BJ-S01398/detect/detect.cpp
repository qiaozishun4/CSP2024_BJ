#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;
double t, n, m, l, V, p[N];

struct car
{
    double d;
    double v;
    double a;
}c[N];

int f(int x, car u)
{
    int fst, fs;
    for(int i = 0; i < m; i++)
    {
        fs = (pow(V) - pow(u.v)) / (2 * u.a);
        for(int j = 0; j < m; j++)
        {
            if(u.a > 0 && p[j] > fs)
            {
                fst = j;
                break;
            }
            if(u.a < 0 && p[j] < fs)
            {
                fst = j;
                break;
            }
        }
    }
    return fst;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.ans", "w", stdout);
    for(int k = 0; k < t; k++)
    {
        cin >> n >> m >> l >> V;
        for(int i = 0; i < n; i++) cin >> c[i].d >> c[i].v >> c[i].a;
        for(int i = 0; i < m; i++) cin >> p[i];
        sort(p, p + m);
        
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}