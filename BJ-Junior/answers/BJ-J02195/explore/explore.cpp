#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;

int T;
int n, m, k;
int ans = 1;

struct tPoint {
    int x, y, d;
}st, cu, nx;
char f[MAXN][MAXN];
bool isw[MAXN][MAXN];

void initval() {
    ans = 1;
    n = 0;
    m = 0;
    k = 0;
    st.x = 0;
    st.y = 0;
    st.d = 0;
    memset(f, 0, sizeof(f));
    memset(isw, 0, sizeof(isw));
}

void readin() {
    cin >> n >> m >> k;
    cin >> st.x >> st.y >> st.d;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> f[i][j];
        }
    }
    cu.x = st.x;
    cu.y = st.y;
    cu.d = st.d;
    isw[cu.x][cu.y] = true;
    //cout << "## " <<cu.x <<" " <<  cu.y <<" " <<cu.d << endl;
}

bool isvalid() {
    if (((nx.x >= 1 && nx.x <= n) && (nx.y >= 1 && nx.y <= m)) && f[nx.x][nx.y] == '.') {
        return true;
    }
    return false;
}

void operation(int mmm) {
    nx.x = cu.x;
    nx.y = cu.y;
    nx.d = cu.d;
    if (nx.d == 0) nx.y++;
    else if (nx.d == 1) nx.x++;
    else if (nx.d == 2) nx.y--;
    else if (nx.d == 3) nx.x--;
    if (isvalid() == true) {
        if (isw[nx.x][nx.y] == false) ans++;
        cu.x = nx.x;
        cu.y = nx.y;
        cu.d = nx.d;
        isw[cu.x][cu.y] = true;
    }
    else {
        cu.d = (cu.d + 1) % 4;
    }
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    for (int iz = 1; iz <= T; ++iz) {
        initval();
        readin();
        for (int i = 1; i <= k; ++i) {
            operation(i);
        }
        cout << ans << endl;
    }
}
