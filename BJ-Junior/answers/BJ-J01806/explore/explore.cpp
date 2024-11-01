#include<iostream>
#include<cstdio>
using namespace std;

char map[1005][1005];
bool s[1005][1005];

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int t;
    cin >> t;

    int n, m, k;
    int x, y, d;
    int x2, y2;
    int sum = 0;
    for (int c = 0; c < t; c++) {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        sum = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++){
                cin >> map[i][j];
                s[i][j] = 0;
            }
        }
        s[x][y] = 1;


        for (int i = 1; i <= k; i++) {
            if(d == 0) {
                x2 = x;
                y2 = y+1;
            } else if(d == 1) {
                x2 = x+1;
                y2 = y;
            } else if(d == 2) {
                x2 = x;
                y2 = y-1;
            } else if(d == 3) {
                x2 = x-1;
                y2 = y;
            }

            if((x2 >= 1 && x2 <= n) && (y2 >= 1 && y2 <= m) && map[x2][y2] == '.'){
                x = x2;
                y = y2;
                s[x2][y2] = 1;
            } else {
                d = (d+1) % 4;
            }
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (s[i][j])
                    sum++;

        cout << sum << endl;
    }


    fclose(stdin);
    fclose(stdout);

    return 0;
}
