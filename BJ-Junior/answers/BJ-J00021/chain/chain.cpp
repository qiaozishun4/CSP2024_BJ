#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct Line
{
    int from, to, id;
};

bool operator ==(const Line x, const Line y)
{
    return x.from == y.from && x.to == y.to && x.id == y.id;
}

Line line[500010];

bool cmp(Line x, Line y)
{
    if (x.from != y.from) return x.from < y.from;
    if (x.to != y.to) return x.to < y.to;
    return x.id < y.id;
}

bool flag[110][200010];
int cnt[200010], first[200010], l[200010], c[200010], r[100010], q[100010];
vector <int> a[200010];

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    memset(flag, 0, sizeof(flag));
    int T;
    cin >> T;
    while (T--)
    {
        int n, k, qs;
        cin >> n >> k >> qs;
        int cur = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &l[i]);
            for (int j = 1; j <= l[i]; j++)
            {
                scanf("%d", &c[j]);
            }
            for (int j = 1; j <= l[i]; j++)
            {
                for (int o = j + 1; o <= l[i] && o <= j + k - 1; o++)
                {
                    line[++cur] = Line{c[j], c[o], i};
                }
            }
        }
        sort(line + 1, line + cur + 1, cmp);
        for (int i = 1; i <= cur; i++)
        {
            if (line[i] == line[i - 1]) continue;
            cnt[line[i].to]++;
            first[line[i].to] = line[i].id;
        }
        Line last = {-1, -1, -1};
        for (int i = 1; i <= cur; i++)
        {
            if (line[i].from == 1) flag[1][line[i].to] = true;
            if (line[i] == line[i - 1]) continue;
            if (cnt[line[i].from] == 0) continue;
            if (cnt[line[i].from] == 1 && first[line[i].from] == line[i].id) continue;
            a[line[i].from].push_back(line[i].to);
            last = line[i];
        }
        int lim = 0;
        for (int i = 1; i <= qs; i++)
        {
            scanf("%d%d", &r[i], &q[i]);
            lim = max(lim, r[i]);
        }

        for (int i = 0; i < a[1].size(); i++)
        {
            //flag[1][a[1][i]] = true;
        }
        for (int i = 2; i <= lim; i++)
        {
            for (int j = 1; j <= 200000; j++)
            {
                if (flag[i - 1][j] == false) continue;
                for (int o = 0; o < a[j].size(); o++)
                {
                    flag[i][a[j][o]] = true;
                }
            }
        }
        /*for (int i = 1; i <= lim; i++)
        {
            for (int j = 1; j <= 6; j++)
            {
                cout << flag[i][j] << " ";
            }
            cout << endl;
        }*/
        for (int i = 1; i <= qs; i++)
        {
            if (flag[r[i]][q[i]]) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
