#include<bits/stdc++.h>
using namespace std;

int t , ma = 0 , c = 0;
int n , m , l , V;  //n车辆数量m测速仪数量l主干道长度v道路限速
const int N = 1e5 + 10;
int d[N] , v[N] , a[N]; //d第i辆车从主干道距离最南端的位置驶入以v的初速和a的加速
int p[N];
bool f[N];

int main(){
    freopen("detect.in" , "r" , stdin);
    freopen("detect.out" , "w" , stdout);
    scanf("%d" , &t);
    for(int i = 1; i <= t; i++){
        c = 0;
        scanf("%d%d%d%d" , &n , &m , &l , &V);
        for(int j = 1; j <= n; j++){
            scanf("%d%d%d" , &d[j] , &v[j] , &a[j]);
        }
        for(int j = 1; j <= m; j++){
            scanf("%d" , &p[j]);
            ma = max(p[j] , ma);
        }
        for(int j = 1; j <= n; j++){
            if(d[j] <= ma && v[j] > V){
                f[j] = true;
                c++;
            }
        }
        printf("%d %d" , c , 1);
    }
    return 0;
}
