

#include <bits/stdc++.h>

using namespace std;

int T;
char _map[1009][1009];
bool _vis[1009][1009];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int _m,_n,_maxi;
int _x,_y,_d;
int _res = 0;

int main () {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin >> T;

    while(T--) {
        _res = 0;

        for(int i = 0; i < 1009; i++) {
            for(int m = 0; m < 1009; m++) {
                _vis[i][m] = false;
            }
        }

        cin >> _n >> _m >> _maxi;
        cin >> _x >> _y >> _d;

        _vis[_x][_y] = true;

        for(int i = 1; i < _n + 1; i++) {
            for(int m = 1; m < _m + 1; m++) {
                cin >> _map[i][m];
            }
        }

        for(int i = 0; i < _maxi; i++) {
            if(_x + dx[_d] < 1 || _y + dy[_d] < 1 || _x + dx[_d] > _n || _y + dy[_d] > _m || _map[_x + dx[_d]][_y + dy[_d]] == 'x') {
                _d = (_d + 1) % 4;
            }

            else{
                _x += dx[_d];
                _y += dy[_d];

                _vis[_x][_y] = true;

            }
        }

        for(int i = 0; i < 1009; i++) {
            for(int m = 0; m < 1009; m++) {
                if(_vis[i][m]) {
                    _res++;
                }
            }

        }

        cout << _res << endl;
    }

    return 0;
}
