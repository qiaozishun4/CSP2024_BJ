#include<bits/stdc++.h>
#define N 100005
using namespace std;
int T;
int n, m, L, V;
struct ve{
    int d, v, a;
    int x;
}car[N];
int det[N];
int maxdet;
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d", &n, &m, &L, &V);
        int tmp = m;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d%d%d", &car[i].d, &car[i].v, &car[i].a);
            if(car[i].v > V) car[i].x = car[i].d;
            else if(car[i].a == 0) car[i].x = L+1;
            else car[i].x = car[i].d+(V*V-car[i].v*car[i].v)/(2*car[i].a)+1;
        }
        for(int i = 1; i <= m; i++){
            scanf("%d", &det[i]);
            maxdet = max(maxdet, det[i]);
        }
        for(int i = 1; i <= n; i++){
            if(car[i].x <= maxdet) cnt++;
        }
        printf("%d %d\n", cnt, (cnt>0)?(m-1):m);
    }
    return 0;
}