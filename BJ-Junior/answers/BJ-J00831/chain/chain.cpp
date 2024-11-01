#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

const int N = 1000;
const int L = 2e5;
const int R = 100;
const int C = 2e5;

struct Node // 结束了第 r 轮，结尾元素为 c，最后一个报数者为 p 者.
{
    int r, c, p;
    inline bool operator < (const Node &b) const
    {
        if (r != b.r) return r < b.r;
        if (c != b.c) return c < b.c;
        return p < b.p;
    }
};

int n, k, q;
int l[N + 5], s[N + 5][L + 5];

vector<pair<int, int>> pos[C + 5]; // c 的位置

bool bfs(Node end)
{
    queue<Node> q;
    map<Node, bool> vis;

    q.push({0, 1, 0});
    while (!q.empty())
    {
        Node u = q.front(); q.pop();
        if (u.r == end.r)
        {
            if (u.c == end.c) return true;
            continue;
        }

        for (auto e : pos[u.c])
        {
            if (e.first == u.p) continue;
            for (int i = 2; i <= k && e.second + i - 1 <= l[e.first]; ++i)
            {
                Node v{u.r + 1, s[e.first][e.second + i - 1], e.first};
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    return false;
}

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> q;
        for (int i = 1; i <= C; ++i) pos[i].clear();

        for (int i = 1; i <= n; ++i)
        {
            cin >> l[i];
            for (int j = 1; j <= l[i]; ++j)
            {
                cin >> s[i][j];
                pos[s[i][j]].push_back({i, j});
            }
        }

        while (q--)
        {
            int r, c;
            cin >> r >> c;
            cout << bfs({r, c}) << endl;
        }
    }

    return 0;
}