#include<bits/stdc++.h>
using namespace std;

int T;
const int N = 1e5+10;
const int maxl = 1e6+10;
int n, m, L, V;

struct cars{
    int d, v, a;
}car[N];

int pos[N];
bool vis[maxl];

float velocity(int vs, int x, int a) { //x is the move from the original space
    return (float)sqrt(vs*vs + 2*a*x);
}

bool cmp(int a, int b) {return a > b;} // the bigger the norther

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while (T--) {
        int ansa = 0;//first answer
        int ansb = 0;//second answer
        scanf("%d %d %d %d", &n, &m, &L, &V);
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &car[i].d, &car[i].v, &car[i].a);
            if (car[i].d > L) car[i].v = 0, car[i].a = 0;
        }
        for (int i = 1; i <= m; i++) scanf("%d", &pos[i]);
        sort(pos+1, pos+m+1, cmp);
        for (int i = 1; i <= n; i++) {
            if (car[i].a == 0) {
                if (car[i].v > V) ansa++;
                if (car[i].d > pos[1]) ansa--;
                if (car[i].v > V) vis[1] = 1;
            }
            else if (car[i].a > 0) {
                ansa += (velocity(car[i].v, pos[1]-car[i].d, car[i].a) <= V ? 0 : 1);
                if (velocity(car[i].v, pos[1]-car[i].d, car[i].a) > V) {
                    vis[1] = 1;
                }
            }
            else {
                int pp = 0;
                for (int j = 1; j <= m; j++) {
                    if (pos[j] < car[i].d) {
                        pp = pos[j-1];
                        if (velocity(car[i].v, pp-car[i].d, car[i].a) > V) vis[j-1] = 1;
                        break;
                    }
                }
                if (pp == 0) continue;
                ansa += (velocity(car[i].v, pp-car[i].d, car[i].a) <= V ? 0 : 1);
            }
        }
        for (int i = 1; i <= m; i++) {
            if (vis[i]) ansb++;
        }
        cout << ansa << " " << m-ansb << "\n";
    }
    return 0;
}
