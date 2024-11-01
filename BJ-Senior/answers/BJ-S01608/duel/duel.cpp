#include <cstdio>
#include <algorithm>
using namespace std;
struct monster{
    int r;
    int time;
    int alive;
};
bool cmp (monster x, monster y){
    return x.r < y.r;
}
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, flag = 0;
    scanf("%d",&n);
    monster a[100005];
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i].r);
        a[i].time = 0, a[i].alive = 1;
        if (a[i].r > 2){
            flag = 1;
        }
    }
    sort (a + 1, a + n + 1, cmp);
    if (flag == 0){
        for (int i = 1; i <= n; i++){
            if (a[i].r == 2){
                printf("%d", n - i + 1);
                return 0;
            }
        }
    }
    flag = 0;
    for (int i = 2; i <= n; i++){
        if (a[i - 1].r == a[i].r){
            flag = 1;
            break;
        }
    }
    if (flag == 0){
        printf("0");
        return 0;
    }
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        for (int j = 1; j <= i - 1; j++){
            if (a[j].alive == 0){
                continue;
            }
            for (int k = j + 1; k <= i; k++){
                if (a[j].r < a[k].r && a[k].time == 0){
                    a[j].alive = 0, a[k].time = 1;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (a[i].alive == 1){
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
