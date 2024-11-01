#include<bits/stdc++.h>
using namespace std;

int T, n, m, l, ans1, ans2, p[100010], pd[100010];
double zca, v1;

struct Node{
    double d, v, a;
}c[100010];

double num(double di, double vi, double ai, double vt){
    return di + (vt * vt - vi * vi) / 2 * ai;
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &T);
    while(T --){
        scanf("%d%d%d%lf", &n, &m, &l, &v1);
        zca = 0;
        ans1 = 0;
        ans2 = 0;
        for(int i = 1; i <= n; i ++){
            scanf("%lf%lf%lf", &c[i].d, &c[i].v, &c[i].a);
            zca += c[i].a;
        }
        for(int i = 1; i <= m; i ++){
            scanf("%d", &p[i]);
            pd[i] = 0;
        }
        if(zca == 0){
            for(int i = 1; i <= n; i ++){
                if(c[i].a == 0){
                    if(c[i].v > double(v1) && c[i].d <= double(p[m])){
                        ans1 ++;
                    }
                }else if(c[i].a > 0){
                    if(num(c[i].d, c[i].v, c[i].a, v1) < double(p[m])){
                        ans1 ++;
                    }
                }else if(c[i].a < 0){
                    int wz = 0;
                    for(int j = 1; i <= m; j ++){
                        if(double(p[j]) >= c[i].d){
                            wz = j;
                            break;
                        }
                    }
                    if(num(c[i].d, c[i].v, c[i].a, v1) > double(p[wz])){
                        ans1 ++;
                    }
                }
            }
            for(int i = 1; i <= m; i ++){
                if(pd[i] == 0){
                    ans2 ++;
                }
            }
            if(ans1 == 0){
                printf("%d %d\n", ans1, ans2);
            }else{
                printf("%d %d\n", ans1, ans2 - 1);
            }
        }else if(zca > 0){
            for(int i = 1; i <= n; i ++){
                double nv = sqrt(c[i].v * c[i].v + 2 * c[i].a * (p[m] - c[i].d));
                if(nv > v1 && c[i].d <= double(p[m])){
                    ans1 ++;
                }
            }
            printf("%d %d\n", ans1, m - 1);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
