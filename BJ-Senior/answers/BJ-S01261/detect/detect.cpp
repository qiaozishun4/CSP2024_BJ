#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N  = 1e5+10;

bool cmp(int a, int b) {return a>b;}

int t;
int p[N];

struct Car {
    int d;
    int v;
    int a;

}car[N];

void work() {
    int ans = 0; // chao shu che liang
    int led = 0; // ce su yi shu liang
    int flag = 0; // xing zhi A
    int n, m, l, v;
    scanf("%lld %lld %lld %lld", &n, &m, &l, &v);

    for (int i=1;i<=n;i++) {
        scanf("%lld %lld %lld", &car[i].d, &car[i].v, &car[i].a);
        if (car[i].a != 0) flag = 1;
    }

    for (int i=1;i<=m;i++) {
        scanf("%lld", &p[i]);
    }

    sort(p+1, p+1+m, cmp);


    if (flag == 0) {
        for (int i=1;i<=n;i++) {
            if (car[i].v > v && car[i].d<=p[1])ans++;
        }
        if (ans != 0) led=m-1;
        else led = m;
        printf("%lld %lld\n", ans, led);
    }


}


signed main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    scanf("%lld", &t);

    while (t--) {
        work();
    }





    return 0;
}
