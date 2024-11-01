#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int NR = 2e5 + 5;

int n, k, m;
vector<int> a[NR * 2];
int b[NR];
int id[NR];
int cnt = 0;

struct node
{
    int x, st;
    bool act;
    int last;
};

int vis[2 * NR];
int bfs1(int s, int t)
{
    queue<node> q;
    memset(vis, -1, sizeof(vis));

    q.push({1, 1, 0, -1});
    vis[1] = 1;

    while (!q.empty())
    {
        int x = q.front().x;
        int st = q.front().st;
        bool act = q.front().act;
        int last = q.front().last;
        q.pop();

        //cout << st << ':' << x << ' ';

        if (st > t)
            continue;
        if (st == t && x == s)
            return 1;


        for (auto it = a[x].begin();it != a[x].end();it ++)
        {
            if (act == 0 && id[*it - NR] == id[last])
                continue;
            if (act == 1 && *it - NR == last)
                continue;
            vis[*it] = st + 1;
            if (act)
                q.push({*it, st + 1, 0, x - NR});
            else
                q.push({*it, st + 1, 1, last});
        }
    }
    return 0;
}

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);

    int T;
    cin >> T;
    while (T --)
    {
        for (int i = 0;i < NR;i ++)
            a[i].clear();
        cnt = 0;

        int u, v;
        cin >> n >> k >> m;
        for (int i = 1;i <= n;i ++)
        {
            int t = cnt;
            cin >> u;
            for (int j = 1;j <= u;j ++)
            {
                cnt ++;
                id[cnt] = i;
                cin >> v;
                b[cnt] = v;
                a[v].push_back(NR + cnt);
                a[NR + cnt].push_back(v);
            }

            for (int j1 = t;j1 <= cnt;j1 ++)
                for (int j2 = j1 + 1;j2 <= cnt && j2 - j1 < k;j2 ++)
                    a[NR + j1].push_back(b[j2]);
        }

        for (int i = 1;i <= m;i ++)
        {
            cin >> u >> v;
            cout << bfs1(v, u * 2 + 1) << '\n';
        }

    }

    return 0;
}
