#include<bits/stdc++.h>
using namespace std;
int t;
double s[100005], e[100005];
bool book[1000005];
bool b1[1000005];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >>t;
    while(t--)
    {
        memset(s, 0, sizeof s);
        memset(e, 0, sizeof e);
        memset(book, 0, sizeof book);
        memset(b1, 0, sizeof b1);
        int n, m, l, V;
        int cnts = 0;
        cin >> n >> m >> l >> V;
        for(int i = 1; i <= n; i++)
        {
            int d, v, a;
            cin >> d >>v >>a;
            if(a == 0)
            {
                if(v > V)
                {
                    cnts++;
                    s[cnts] = d;
                    e[cnts] = l;
                }
            }
            if(a > 0)
            {
                if(v > V)
                {
                    cnts++;
                    s[cnts] = d;
                    e[cnts] = l;
                    continue;
                }
                double tmp = 1.0 * d + (V * V - v * v) / 2 * a;
                if(tmp < l)
                {
                    cnts++;
                    s[cnts] = tmp + 0.0001;
                    e[cnts] = l;
                }
            }
            if(a < 0)
            {
                if(v < V) continue;
                double tmp = 1.0 * d + (V * V - v * v) / 2 * a;
                if(tmp > d)
                {
                    cnts++;
                    s[cnts] = d;
                    e[cnts] = tmp - 0.0001;
                }
            }
        }
        sort(s + 1, s + cnts + 1);
        sort(e + 1, e + cnts + 1);
        for(int i = 1; i <= m; i++)
        {
            int k;
            cin >> k;
            book[k] = 1;
        }
        int sumc = 0, sump = 0;
        for(int i = 1; i <= cnts; i++)
        {
            bool flag = 1, flag1 = 0; int mr;
            for(int j = floor(e[i]); j >= ceil(s[i]); j--)
            {
                if(book[j])
                {
                    if(flag)
                    {
                        sumc++;
                        flag = 0;
                        mr  = j;
                    }
                }
                if(b1[j]) flag1 = 1;
            }
            if(!flag1)
            {
                b1[mr] = 1;
                sump++;
            }

        }
        cout << sumc << " " << m - sump - 1 << endl;
    }
    return 0;
}
