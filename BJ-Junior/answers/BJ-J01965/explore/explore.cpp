#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

#define MY_TEST

void read(int &rtn) {
    char c = getchar();
    bool rev = false;
    rtn = 0;
    while (c < '0' || c > '9')
        rev |= (c == '-'), c = getchar();
    while (c >= '0' && c <= '9')
        rtn = (rtn << 3) + (rtn << 1) + c - 48, c = getchar();
    if (rev) rtn = -rtn;
}
void read(ll &rtn) {
    char c = getchar();
    bool rev = false;
    rtn = 0LL;
    while (c < '0' || c > '9')
        rev |= (c == '-'), c = getchar();
    while (c >= '0' && c <= '9')
        rtn = (rtn << 3) + (rtn << 1) + c - 48, c = getchar();
    if (rev) rtn = -rtn;
}
void read(char &rtn) {
    char c = getchar();
    while (c != '.' && c != 'x')
        c = getchar();
    rtn = c;
}

const int maxn = 1010, maxsz = 4000010;
const int mv[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int n, m, k;
bool mp[maxn][maxn], vis[maxn][maxn][4];

bool out(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }

int queue[maxsz][4], lt, rt;
void bfs(int st_x, int st_y, int st_d) {
    lt = 0, rt = 1;
    queue[0][0] = st_x, queue[0][1] = st_y, queue[0][2] = st_d, queue[0][3] = 0;
    vis[st_x][st_y][st_d] = true;
    while (lt < rt) {
        const int x = queue[lt][0], y = queue[lt][1], d = queue[lt][2], step = queue[lt][3];
        ++lt;
        // printf("%d: %d %d %d %d\n", lt-1,x,y,d,step);
        const int mvx = x + mv[d][0], mvy = y + mv[d][1];
        int nx, ny, nd;
        if (out(mvx, mvy) || mp[mvx][mvy])
            nx = x, ny = y, nd = (d + 1) % 4;
        else nx = mvx, ny = mvy, nd = d;
        if (vis[nx][ny][nd]) continue;
        vis[nx][ny][nd] = true;
        if (step + 1 < k)
            queue[rt][0] = nx, queue[rt][1] = ny, queue[rt][2] = nd, queue[rt][3] = step + 1, ++rt;
    }
}

int main() {
    #ifdef MY_TEST
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    #else
    freopen("explore5.in", "r", stdin);
    freopen("explore5.out", "w", stdout);
    #endif

    char c;
    int T, x, y, d;
    read(T);
    while (T--) {
        memset(vis, 0, sizeof(vis));
        read(n), read(m), read(k);
        read(x), read(y), read(d);
        --x, --y;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                read(c);
                mp[i][j] = (c == 'x');
            }
        }
        bfs(x, y, d);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans += (vis[i][j][0] || vis[i][j][1] || vis[i][j][2] || vis[i][j][3]);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}