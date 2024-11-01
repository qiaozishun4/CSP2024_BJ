#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10e3 + 20;

int n, m, k, T, x, y, d;
string imp;

bool mmap[MAXN][MAXN];
bool fs[MAXN][MAXN];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void map_init(){
    memset(mmap, 0, sizeof mmap);
    memset(fs, 0, sizeof fs);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            mmap[i][j] = 1;
        }
    }
}

void printmap(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << fs[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    scanf("%d", &T);
    for(; T > 0; T--){
        scanf("%d%d%d", &n, &m, &k);
        map_init();
        scanf("%d%d%d", &x, &y, &d);
        for(int i = 1; i <= n; i++){
            cin >> imp;
            for(int j = 1; j <= m; j++){
                if (imp[j-1] == 'x'){
                    mmap[i][j] = 0;
                }

            }
        }
        for(; k >= 0; k--){
            fs[x][y] = 1;
            //printmap();
            int nx = x + dx[d];
            int ny = y + dy[d];
            //out << nx << ' ' <<ny <<endl;
            if (mmap[nx][ny]){
                x = nx;
                y = ny;
            }
            else{
                d = (d + 1) % 4;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if (fs[i][j]){
                    ans++;
                }

            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
