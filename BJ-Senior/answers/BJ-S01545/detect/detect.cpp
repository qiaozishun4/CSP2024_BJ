#include<bits/stdc++.h>
using namespace std;
struct line{
    int st, ed;
    bool isp;
}l[100005];
struct car{
    int d, v, a;
}c[100005];
struct inf{
    int ii;
    int ct;
    int cut[100005];
}inff[100005];

bool cmp(inf a, inf b) {
    return a.ct > b.ct;
}
line calc(int x, int dx, int ddx, int limv, int limd) {
    int ans = 0;
    line cnt;
    if(ddx > 0) {
        if(dx > limv) {
            cnt.st = x;
            cnt.ed = limd;
        }else{
            ans = (limv * limv - dx * dx) / 2 / ddx;
            cnt.st = ans + x;
            cnt.ed = limd;
        }
    }
    if(ddx < 0) {
        if(dx < limv) {
            cnt.st = -1;
            cnt.ed = -1;
        }else{
            ans = dx * dx / 2 / abs(ddx);
            cnt.st = x;
            cnt.ed = ans + x;
        }
    }
    if(ddx == 0) {
        if(dx < limv) {
            cnt.st = -1;
            cnt.ed = -1;
        }
        if(dx > limv) {
            cnt.st = x;
            cnt.ed = limd;
        }
    }
    cnt.isp = false;
    return cnt;
}
bool check() {
    int i = 0;
    while(l[i].isp) {
        if(l[i].isp == false) {
            return false;
        }
        i++;
    }
    return true;
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int n, m, L, V;
    int p[100005];
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        cin >> m;
        cin >> L;
        cin >> V;
        for(int i = 0; i < n; i++) {
            cin >> c[i].d;
            cin >> c[i].v;
            cin >> c[i].a;
            l[i] = calc(c[i].d, c[i].v, c[i].a, V, L);
        }
        for(int i = 0; i < m; i++) {
            cin >> p[i];
        }
        int an = 0;
        for(int i = 0 ; i < n; i++) {
            if(l[i].st != -1) {
                an++;
            }
        }
        int k = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(p[i] < l[j].ed && p[i] > l[j].st) {
                    inff[i].ii = i;
                    inff[i].ct++;
                    inff[i].cut[k] = j;
                    k++;
                }
            }
        }
        sort(inff, inff + m, cmp);
        int cn = 0;
        while(!check()) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    l[inff[i].cut[j]].isp = true;
                }
            }
            cn++;
        }
        cout << an << " " << m - cn << endl;
        for(int i = 0; i < m; i++) {
            p[i] = 0;
        }
    }
    return 0;
}