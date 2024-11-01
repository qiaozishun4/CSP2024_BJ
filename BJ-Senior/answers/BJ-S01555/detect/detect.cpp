#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct car{
    int d,v,a;
    bool chaosu = false;
};

void solve(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int n, m, L, V;
    scanf("%d %d %d %d",&n,&m,&L,&V);
    vector<car> cars(n + 1);
    vector<int> detection(m + 1);
    for(int i = 1; i <= n; ++i)
        scanf("%d %d %d",&cars[i].d,&cars[i].v,&cars[i].a);
    for(int i = 1; i <= m; ++i)
        scanf("%d",&detection[i]);
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(cars[i].d > detection[j] || detection[j] > L || cars[i].d > L)
                continue;
            if(cars[i].a == 0) {
                if(cars[i].v > V){
                    ++ans;
                    break;
                }
            } else {
                double v1 = sqrt(abs(2 * cars[i].a * abs(detection[i] - cars[i].d) + cars[i].v * cars[i].v));
                if(v1 > V){
                    cars[i].chaosu=true;
                    break;
                }
            }
        }
        if(cars[i].chaosu)
            ++ans;
    }
    printf("%d %d\n",ans,m-3);
    return;
}
int main(){
    freopen("detect.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
