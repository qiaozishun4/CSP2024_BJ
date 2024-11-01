#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50,INF = 0x3f3f3f3f;
int t,n,m,l,v;
struct Car{int d,v,a;}car[maxn];
int p[maxn];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int maxxp = -INF,minna = INF,maxxa = -INF,maxxd = -INF;
        int ans1 = 0,ans2 = 0;
        scanf("%d%d%d%d",&n,&m,&l,&v);
        for(int i = 1;i <= n;i++){
            scanf("%d%d%d",&car[i].d,&car[i].v,&car[i].a);
            minna = min(minna,car[i].a);
            maxxa = max(maxxa,car[i].a);
            maxxd = max(maxxd,car[i].d);
        }

        for(int i = 1;i <= m;i++){
            scanf("%d",&p[i]);
            maxxp = max(maxxp,p[i]);
        }

        if(minna == 0 && maxxa == 0){
            for(int i = 1;i <= n;i++){
                if(car[i].v > v && maxxp >= car[i].d)ans1++;
            }
            if(ans1 == 0)ans2 = m;
            else {
                if(maxxp >= maxxd){
                    ans2 = m - 1;
                }
                else {
                    sort(p + 1,p + 1 + m);
                    for(int i = m;i >= 1;i--){
                        if(p[i] < maxxd){
                            ans2 = m - i;
                        }
                    }
                }
            }
            printf("%d %d\n",ans1,ans2);
        }
        else if(minna > 0){
            int x[maxn];
            for(int i = 1;i <= n;i++){
                if(car[i].v <= v){
                    x[i] = floor(((double)v * (double)v - (double)car[i].v * (double)car[i].v) / (2.0 * (double)car[i].a)) + 1;
                    car[i].d += x[i];
                    car[i].v = v + 1;
                    maxxd = max(maxxd,car[i].d);
                }
            }
            for(int i = 1;i <= n;i++){
                if(car[i].d <= l - 1 && maxxp >= car[i].d)ans1++;
            }
            if(ans1 == 0)ans2 = m;
            else {
                if(maxxp >= maxxd){
                    ans2 = m - 1;
                }
                else {
                    sort(p + 1,p + 1 + m);
                    for(int i = m;i >= 1;i--){
                        if(p[i] < maxxd){
                            ans2 = m - i;
                        }
                    }
                }
            }
            printf("%d %d\n",ans1,ans2);
        }
        else if(maxxa < 0){
            double x[maxn];
            for(int i = 1;i <= n;i++){
                if(car[i].v > v){
                    x[i] = ((double)v * (double)v - (double)car[i].v * (double)car[i].v) / (2.0 * (double)car[i].a);
                }
                else x[i] = 0.0;
                maxxd = (maxxd,car[i].d + x[i]);
            }
            sort(p + 1,p + 1 + m);
            for(int i = 1;i <= n;i++){
                if(car[i].v > v ){
                    for(int j = 1;j <= m;j++){
                        if(p[j] >= car[i].d && (double)p[j] < (double)car[i].d + (double)x[i]){
                            ans1++;
                            break;
                        }
                    }
                }
            }
            int xx[maxn],tot = 0;
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= m;j++){
                    if(p[j] >= car[i].d && (double)p[j] < (double)car[i].d + (double)x[i])xx[++tot] = j;
                }
            }
            int ans = unique(xx + 1,xx + 1 + tot) - xx;
            printf("%d %d\n",ans1,ans);
        }
    }
    return 0;
}
