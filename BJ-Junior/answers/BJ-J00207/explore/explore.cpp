#include <iostream>

using namespace std;

int t;
int n, m, k;
int x, y, d;
int tmpx, tmpy;
int ans;
char a[1005][1005];
bool book[1005][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> t;

    for (int i = 1; i <= t; i += 1) {
        for (int bookx = 1; bookx <= n; bookx += 1) {
            for (int booky = 1; booky <= m; booky += 1) {
                book[bookx][booky] = false;
            }
        }
        
        ans = 1;

        cin >> n >> m >> k;
        cin >> x >> y >> d;

        for (int mapx = 1; mapx <= n; mapx += 1) {
            for (int mapy = 1; mapy <= m; mapy += 1) {
                cin >> a[mapx][mapy];
            }
        }

        book[x][y] = true;

        for (int j = 1; j <= k; j += 1) {
            if (d == 0) {
                tmpx = x;
                tmpy = y + 1;
            }

            if (d == 1) {
                tmpx = x + 1;
                tmpy = y;
            }

            if (d == 2) {
                tmpx = x;
                tmpy = y - 1;
            }

            if (d == 3) {
                tmpx = x - 1;
                tmpy = y;
            }

            if ((1 <= tmpx && tmpx <= n) && (1 <= tmpy && tmpy <= m) && a[tmpx][tmpy] == '.') {
                x = tmpx;
                y = tmpy;
                
                if (book[x][y] == false) {
                    book[x][y] = true;
                    ans += 1;
                }
            } else {
                d = (d + 1) % 4;
            }
        }

        cout << ans << endl;
    }

    return 0;
}