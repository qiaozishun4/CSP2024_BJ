#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
int T,n,m,L,V;
int p[MAXN];

struct Car{
    int d;
    int v;
    int a;
    Car(){}
    Car(int d,int v,int a):d(d),v(v),a(a){}
};
Car cars[MAXN];

struct Range{
    int l;
    int r;
    Range(){}
    Range(int l,int r):l(l),r(r){}
};
vector<Range> rs;

inline bool operator < (Range a,Range b){
    if (a.r != b.r)return a.r < b.r;
    return a.l > b.l;
}

inline bool in(Range big,Range small){
    return small.l >= big.l && small.r <= big.r;
}

int main(){
    #ifndef kevin
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    #endif
    scanf("%d",&T);
    while (T --){
        rs.clear();
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for (int i = 1;i <= n;i ++)scanf("%d%d%d",&cars[i].d,&cars[i].v,&cars[i].a);
        for (int i = 1;i <= m;i ++)scanf("%d",p + i);
        sort(p + 1,p + m + 1);
        for (int i = 1;i <= n;i ++){
            Car &c = cars[i];
            if (c.a == 0){
                if (c.v <= V){
                    // printf("%d ok\n",i);
                    continue;
                }
                rs.push_back(Range(lower_bound(p + 1,p + m + 1,c.d) - p,m));
            }
            if (c.a > 0){
                if (c.v > V){
                    rs.push_back(Range(lower_bound(p + 1,p + m + 1,c.d) - p,m));
                    continue;
                }
                ll div = ((ll)V * V - (ll)c.v * c.v) / (c.a << 1);
                if (div > (ll)p[m]){
                    // printf("%d ok\n",i);
                    continue;
                }
                rs.push_back(Range(upper_bound(p + 1,p + m + 1,c.d + div) - p,m));
            }
            if (c.a < 0){
                if (c.v <= V){
                    // printf("%d ok\n",i);
                    continue;
                }
                int nxt = lower_bound(p + 1,p + m + 1,c.d) - p,l = nxt - 1,r = m;
                if (l > r){
                    // printf("%d ok\n",i);   
                    continue;
                }
                while (l < r){
                    int mid = (l + r + 1) >> 1;
                    if ((ll)(p[mid] - c.d) * c.a * 2ll > (ll)V * V - (ll)c.v * c.v)l = mid;
                    else r = mid - 1;
                }
                rs.push_back(Range(nxt,r));
            }
        }
        // for (auto it : rs)printf("[%d,%d]\n",it.l,it.r);
        for (int i = 0;i < (int)rs.size();i ++){
            if (rs[i].l > rs[i].r){
                swap(rs[i],rs.back());
                rs.pop_back();
                i --;
                continue;
            }
        }
        printf("%d ",(int)rs.size());
        sort(rs.begin(),rs.end());
        int p = 0;
        for (int i = 0;i < (int)rs.size();i ++){
            if (!i || !in(rs[i],rs[i - 1]))
                rs[p ++] = rs[i];
        }
        rs.resize(p);
        // for (auto it : rs)printf("[%d,%d]\n",it.l,it.r);
        int lst = -1;
        int cnt = 0;
        for (auto it : rs)
            if (lst < it.l){
                lst = it.r;
                cnt ++;
            }
        printf("%d\n",m - cnt);
    }
    return 0;
}