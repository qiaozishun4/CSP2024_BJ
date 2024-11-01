#include<bits/stdc++.h>
using namespace std;

const int maxN = 1010;
bool vst[maxN][maxN];
vector<string> mp;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int t, n, m, k, cx, cy, cd, ii, ax, ay, resu;
    cin >> t;
    while (t>0) {
        --t;
        cin >> n >> m >> k;
        cin >> cx >> cy >> cd;
        mp.resize(n+1);
        for (ii=0 ; ii<n ; ++ii) { cin >> mp[ii]; }

        resu = 1;
        --cx; --cy;
        memset(vst, false, sizeof(vst));
        vst[cx][cy] = true;

        for (ii=0 ; ii<k ; ++ii) {
            ax = cx + dx[cd]; ay = cy + dy[cd];
            if (ax>=0 && ax<n && ay>=0 && ay<m && mp[ax][ay]=='.') {
                cx=ax; cy=ay;
            } else {
                cd = (cd + 1) % 4;
            }
            if (!vst[cx][cy]) {\
                ++resu;
                vst[cx][cy] = true;
            }
        }
        cout << resu << endl;
    }

    return 0;
}

