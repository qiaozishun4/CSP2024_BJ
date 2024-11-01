#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

#define MP make_pair
#define F first
#define S second
const int N = 1e5;
const double P = 1e-5;

int t, n, m, L, V, cnt, last, ans;
bool status;
int d[N], v[N], a[N], p[N];
pair<int, int> op[2 * N];

int findr(double x, bool b)
{
    int l = 0, r = m - 1, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (p[mid] > x || (b && abs(p[mid] - x) < P))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int findl(double x, bool b)
{
    int l = 0, r = m - 1, mid;
    while (l < r)
    {
        mid = (l + r) / 2 + (l + r) % 2;
        if (p[mid] < x || (b && abs(p[mid] - x) < P))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}

int main(void)
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    cin >> t;
    while (t--)
    {
        cin >> n >> m >> L >> V;
        for (int i = 0; i < n; i++)
        {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> p[i];
        }

        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (d[i] > p[m - 1])
            {
                continue;
            }
            if (a[i] < 0)
            {
                if (v[i] > V && d[i] + (double)1.0 * (v[i] * v[i] - V * V) / 2 / (-a[i]) > p[0])
                {
                    //cout<<i<<' ';
                    op[cnt * 2] = MP(findr(d[i], true), -1);
                    op[cnt * 2 + 1] = MP(findl(d[i] + (double)1.0 * (v[i] * v[i] - V * V) / 2 / (-a[i]), false), op[cnt * 2].F);
                    if (op[cnt * 2].F <= op[cnt * 2 + 1].F)
                    {
                        cnt++;
                    }
                }
            }
            else if (a[i] == 0)
            {
                if (v[i] > V)
                {
                    //cout<<i<<' ';
                    op[cnt * 2] = MP(findr(d[i], true), -1);
                    op[cnt * 2 + 1] = MP(m - 1, op[cnt * 2].F);
                    if (op[cnt * 2].F <= op[cnt * 2 + 1].F)
                    {
                        cnt++;
                    }
                }
            }
            else
            {
                if (v[i] > V)
                {
                    //cout<<i<<' ';
                    op[cnt * 2] = MP(findr(d[i], true), -1);
                    op[cnt * 2 + 1] = MP(m - 1, op[cnt * 2].F);
                    if (op[cnt * 2].F <= op[cnt * 2 + 1].F)
                    {
                        cnt++;
                    }
                }
                else if (sqrt(v[i] * v[i] + 2 * a[i] * (p[m - 1] - d[i])) > V)
                {
                    //cout<<i<<' ';
                    op[cnt * 2] = MP(findr(d[i] + (double)1.0 * (V * V - v[i] * v[i]) / 2 / a[i], false), -1);
                    op[cnt * 2 + 1] = MP(m - 1, op[cnt * 2].F);
                    if (op[cnt * 2].F <= op[cnt * 2 + 1].F)
                    {
                        cnt++;
                    }
                }
            }
        }

        //cout<<endl;
        /*for (int i = 0; i < cnt; i++)
        {
            cout<<op[i * 2].F<<' '<<op[i * 2 + 1].F<<endl;
        }
        cout<<endl;*/

        ans = 0;
        last = -1;
        status = 1;
        sort(op, op + cnt * 2);
        for (int i = 0; i < cnt * 2; i++)
        {
            //cout<<op[i].F<<' '<<op[i].S<<' '<<last<<' ';
            if (op[i].S == -1)
            {
                if(status && (op[i].F > last))
                {
                    //cout<<op[i].F<<' ';
                }
                ans += status && (op[i].F > last);
                if (op[i].F > last)
                {
                    status = 0;
                }
            }
            else
            {
                if (op[i].S > last)
                {
                    status = 1;
                    last = max(last, op[i].F);
                }
            }
            //cout<<endl;
        }
        //cout<<endl;
        cout << cnt << ' ' << m - ans << endl;
    }

    return 0;
}