#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int T, n, m, L, V;
struct node{
    int d, v, a, num;
    double l, r;
}c[N];
ll ans1, ans2;
int p[N];
vector<int> fin;
vector<int> f[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf(" %d",&T);
    while(T--){
        ans1 = ans2 = 0;
        memset(c, 0, sizeof(c));
        memset(p, 0, sizeof(p));
        memset(f, 0, sizeof(f));
        fin.clear();
        scanf(" %d %d %d %d",&n,&m,&L,&V);
        for(int i = 1; i <= n; i++){
            scanf(" %d %d %d",&c[i].d,&c[i].v,&c[i].a);
            if(c[i].a <= 0 && c[i].v < V) c[i].r = c[i].l = -1;
            else if(c[i].v > V && c[i].a >= 0) c[i].l = c[i].d, c[i].r = L;
            else if(c[i].a < 0){
                c[i].l = (double)c[i].d;
                c[i].r = (((c[i].v * c[i].v - V * V) * 0.01) / (c[i].a * -0.02)) > L ? L : c[i].d + ((c[i].v * c[i].v - V * V) * 0.01) / (c[i].a * -0.02);
            }
            else if(c[i].a > 0){
                c[i].r = L;
                c[i].l = ((V * V - c[i].v * c[i].v) * 0.01) / (c[i].a * 0.02) + c[i].d;
            }
            //printf("%d: %lf, %lf\n",i, c[i].l, c[i].r);
        }
        for(int i = 1; i <= m; i++){
            scanf(" %d",&p[i]);
        }
        for(int i = 1; i <= n; i++){
            if(c[i].l == c[i].r && c[i].l == 0) continue;
            for(int j = 1; j <= m; j++){
                if(p[j] >= c[i].l && p[j] <= c[i].r){
                    ans1++;
                    break;
                }
            }
        }
        printf("%lld ",ans1);
        ll cntz = 0;
        bool exit = false;
        for(int i = 1; i <= n; i++){
            if(c[i].l == c[i].r && c[i].l == 0) continue;
            for(int j = 1; j <= m; j++){
                if(p[j] >= c[i].l && p[j] <= c[i].r){
                    cntz++;
                    if(cntz == ans1){
                        printf("%lld",ans1 - 1);
                        exit = true;
                    }
                    if(cntz == ans1 - 1){
                        printf("%lld", ans1 - 2);
                        exit = true;
                    }
                    f[i].push_back(j);
                }
                if(exit) break;
            }
            if(exit) break;
        }
        if(exit) continue;
        for(int i = 0; i < n; i++){
            if(f[i].size() == 1){
                fin.push_back(f[i][0]);
                continue;
            }
            int maxx = 0;
            for(int j = 0; j < fin.size(); j++){
                for(int k = 0; k < f[i].size(); k++){
                    if(f[i][k] == fin[j]){
                        maxx = 1;
                        break;
                    }
                }
                if(maxx) break;
            }
            if(!maxx){
                for(int j = 0; j < f[i].size(); j++){
                    maxx = max(maxx, f[i][j]);
                }
                fin.push_back(maxx);
            }
        }
        printf("%d",(int)fin.size());
        puts("");
    }
    return 0;
}
