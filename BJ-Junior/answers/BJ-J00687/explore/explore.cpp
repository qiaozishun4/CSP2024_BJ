#include <cstdio>
#include <cstring>
#include <utility>
#include <tuple>
#include <queue>

using namespace std;

const int N = 1010;
const int X = 0, Y = 1, D = 2;

typedef tuple<int, int, int> Point;

queue<Point> q;
bool vis[N][N];
int step[N][N];
char g[N][N];
int n, m, k;
int dx[] { 0, 1, 0, -1 }, dy[] { 1, 0, -1, 0 };

bool inArea(Point pt)
{
    int x = get<X>(pt), y = get<Y>(pt);
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int bfs(Point pt)
{
    queue<Point> tmp;
    swap(q, tmp);
    int x = get<X>(pt), y = get<Y>(pt), d = get<D>(pt);
    q.emplace(x, y, d);
    vis[x][y] = true;
    int ans = 1;
    while (!q.empty())
    {
        pt = q.front();
        q.pop();
        x = get<X>(pt); y = get<Y>(pt); d = get<D>(pt);
        //printf("q popped a Point Info : (x = %d, y = %d, d = %d)\n", x, y, d);
        if (step[x][y] == k)
        {
            continue;
        }
        int newX = x + dx[d], newY = y + dy[d];
        //printf("new pt = (%d, %d)\n", newX, newY);
        Point newPt = make_tuple(newX, newY, d);
        for (int turn = 0; turn < 4 && step[x][y] + turn + 1 <= k; ++turn)
        {
            if (inArea(newPt) && !vis[newX][newY] && g[newX][newY] == '.')
            {
                q.emplace(newX, newY, d);
                vis[newX][newY] = true;
                step[newX][newY] = step[x][y] + turn + 1;
               // printf("step[%d][%d] = step[%d][%d] + %d + 1 equals %d\n", newX, newY, x, y, turn, step[newX][newY]);
                ++ans;

            }
            d = (d + 1) & 3;
            newPt = make_tuple(newX = x + dx[d], newY = y + dy[d], d);
        }
    }
    return ans;
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t, x0, y0, d0;
    scanf("%d", &t);
    while (t--)
    {
        memset(vis, false, sizeof(vis));
        memset(step, 0, sizeof(step));
        scanf("%d%d%d%d%d%d", &n, &m, &k, &x0, &y0, &d0);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", g[i] + 1);
        }
        printf("%d", bfs({x0, y0, d0}));
     //   printf("\nstep : \n");

    }
    return 0;
}
