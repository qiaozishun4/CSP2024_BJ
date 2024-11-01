#include<bits/stdc++.h>
using namespace std;

float starta;
float downa;

struct numbera {
    float d;
    int va;
    int a;
};

void sudu(float d, int va, int a, int l, int v) {
    if(a == 0) {
        if(va > v) {
            starta = d - 1;
            downa = l + 1;
        } else {
            starta = -1;
            downa = -1;
        }
    } else {
        int k = v * v - va * va;
        int p = 2 * a;
        float longabc = k / p;
        longabc = longabc + d;
        if(a > 0) {
            starta = longabc;
            downa = l + 1;
        } else if(a < 0) {
            starta = d - 1;
            downa = longabc;
        }
    }
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int team;
    cin >> team;
    int n;
    int m;
    float l;
    int v;
    while(team--) {
        cin >> n >> m >> l >> v;
        int chaosu = 0;
        numbera car[n];
        float p[m];
        for(int i = 0; i < n; ++i) {
            cin >> car[i].d >> car[i].va >> car[i].a;
        }
        for(int i = 0; i < m; ++i) {
            cin >> p[i];
        }
        for(int i = 0; i < n; ++i) {
            sudu(car[i].d, car[i].va, car[i].a, l, v);
            for(int j = 0; j < m; ++j) {
                if(p[j] > starta && p[j] < downa) {
                    chaosu = chaosu + 1;
                    break;
                }
            }
        }
        cout << chaosu << endl;
    }
    return 0;
}
