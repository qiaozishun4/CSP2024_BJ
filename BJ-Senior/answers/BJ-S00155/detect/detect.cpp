#include <bits/stdc++.h>
#define int long long
using namespace std;
int c[100010];
int d[100010];
int v[100010];
int a[100010];
struct Node
{
    int x, y, id;
    bool f;
} ch[100010];
bool cmp2(Node s1, Node s2)
{
    return s1.y < s2.y;
}
bool cmp1(Node s1, Node s2)
{
    return s1.x < s2.x;
}
signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int cnt = 0;
        int n, m, l, V;
        cin >> n >> m >> l >> V;
        for(int i = 1; i <= n; i++)
        {
            cin >> d[i] >> v[i] >> a[i];
        }
        for(int i = 1; i <= m; i++)
        {
            cin >> c[i];
        }
        sort(c + 1, c + m + 1);
        int dd = 0;
        for(int i = 1; i <= n; i++)
        {
            if(v[i] <= V && a[i] <= 0)
            {
                ch[i].x = ch[i].y = -1;
                dd++;
            }
            else if(v[i] > V && a[i] >= 0)
            {
                ch[i].x = d[i];
                ch[i].y = l;
            }
            else
            {
                long double u = (V * V - v[i] * v[i]) / (2.0 * a[i]) + d[i];
                if(a[i] > 0)
                {
                    ch[i].x = u + 1;
                    ch[i].y = l;
                }
                else
                {
                    ch[i].x = d[i];
                    ch[i].y = u;
                    if((V * V - v[i] * v[i]) % (2 * a[i]) == 0) ch[i].y--;
                }
            }
            ch[i].id = i;
        }
        sort(ch + 1, ch + n + 1, cmp1);
        int op = 1;

        for(int i = 1; i <= m; i++)
        {
            while(op <= n && ch[op].y < c[i])
            {
                op++;
            }
            while(op <= n && ch[op].x <= c[i] && c[i] <= ch[op].y)
            {
                ch[op].f = 1;
                op++;
                cnt++;
            }
        }

        sort(ch + 1, ch + n + 1, cmp2);
        cout << cnt << ' ';
        op = 1;
        cnt = 0;

        for(int i = 1; i <= n; i++)
        {
            if(!ch[i].f) continue;
            while(op <= m && !(c[op] >= ch[i].x && c[op] <= ch[i].y && (op == m || c[op + 1] > ch[i].y)))
            {
                op++;
            }
            cnt++;
            ch[i].f = 0;
            i++;
            while(i <= n && ch[i].x <= c[op] && ch[i].y >= c[op])
            {
                ch[i].f = 0;
                i++;
            }
            i--;
        }
        cout << m - cnt << endl;

    }
    return 0;
}
//HF#24THMC
/*10 10 99858 982
39033 1000 -2
26456 999 -1
25617 37 -242
28141 1000 -1
27960 995 -6
1452 988 -58
44970 993 -322
16069 998 -1
26508 999 -1
44686 993 -1
1460 14938 17798 29360 42181 44971 55154 55534 74909 99858*/
