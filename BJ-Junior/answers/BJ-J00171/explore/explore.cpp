#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int NMAX = 1100;
const int MMAX = 1100;
const int DMAX = 4;

int T;
int N, M, K;
int X0, Y0, D0;
char grid[NMAX][MMAX];
bool visit[NMAX][MMAX];
int dir[DMAX][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

bool in_grid(int x, int y)
{
    return 1 <= x && x <= N && 1 <= y && y <= M;
}

void try_move(int &x, int &y, int &d)
{
    int nxt_x = x + dir[d][0];
    int nxt_y = y + dir[d][1];
    if(in_grid(nxt_x, nxt_y) && grid[nxt_x][nxt_y] == '.') {
        x = nxt_x;
        y = nxt_y;
    } else {
        d = (d + 1) % DMAX;
    }
}

int try_mark(int x, int y)
{
    int res = 0;
    if(!visit[x][y]) {
        res = 1;
        visit[x][y] = true;
    }
    return res;
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d", &T);
    for(int t = 1;t <= T;t += 1) {
        scanf("%d %d %d", &N, &M, &K);
        scanf("%d %d %d", &X0, &Y0, &D0);
        for(int i = 1;i <= N;i += 1) {
            for(int j = 1;j <= M;j += 1) {
                scanf(" %c", &grid[i][j]);
                visit[i][j] = false;
            }
        }
        int ans = 0;
        int x = X0, y = Y0, d = D0;
        ans += try_mark(x, y);
        for(int i = 1;i <= K;i += 1) {
            try_move(x, y, d);
            ans += try_mark(x, y);
            // printf("%d: (x: %d, y: %d, d: %d)\n", i, x, y, d);
        }
        printf("%d\n", ans);
    }
    exit(0);
}