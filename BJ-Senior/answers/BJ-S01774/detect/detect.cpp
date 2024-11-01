#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int T;
int n, m, L, V;
int cnt = 0, delpos = 0;

//kaA
int maxovs = 0;

struct tCar{
    int d, v, a;
}c[MAXN];

struct tPos{
    int pl;
    bool undab = false;
}pos[MAXN];

int ttlpos = 1;
//bool p[MAXN];

void initval() {
    memset(c, 0, sizeof(c));
    memset(pos, 0, sizeof(pos));
    cnt = 0;
}

void readin() {
    cin >> n >> m >> L >> V;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i].d >> c[i].v >> c[i].a;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> pos[i].pl;
        //pos[ttlpos] = i;
        ttlpos++;
        //cin >> temp;
        //p[temp] = true;
    }
    for (int i = 1; i <= m; ++i) {
        //cout << pos[i].pl << " ";
    }
    //cout << endl;
}

void pros () {
    for (int i = 1; i <= n; ++i) {
        if (c[i].v > V && c[i].d <= pos[m].pl) {
            cnt++;
            //for (int j = 1; j <= m; ++j) {
                //if(pos[j].pl >= c[i].d && pos[j].undab == false) {
                //    pos[j].undab = true;
                //    //cout << "! When " << "a ovspd car ent in " << c[i].d << ", #pos " << j <<" not del able." << endl;
                //}
            //}
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (pos[i].undab == true) {
            break;
        }
        delpos++;
    }
}

void outp() {
    if (cnt != 0) cout << cnt << " " << m-1 << endl;
    else cout << cnt << " " << m << endl;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    for (int iz = 1; iz <= T; ++iz) {
        initval();
        readin();
        pros();
        outp();
    }

    return 0;
}
