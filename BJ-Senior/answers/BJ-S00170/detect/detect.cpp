#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXL 1000005
#define eps 1e-5

int n,m,L;
double V;
int d[MAXN],v[MAXN],a[MAXN],p[MAXN];
int l[MAXN],r[MAXN];
int sum[MAXL];
int cal(int dd,int vv,int aa){
    long long tmp = V * V - vv * vv;
    if(aa > 0){
        if(tmp % (2 * aa )== 0) return tmp / (2 * aa) + dd + 1;
        else return ceil((double)tmp / (double)(2.0 * aa)) + dd;
    }else{
        if(tmp % (2 * aa) == 0) return tmp / (2 * aa) + dd - 1;
        else return floor((double)tmp / (double)(2.0 * aa)) + dd;
    }
}
struct kkk{
    int ll,rr;
    bool operator <(const kkk ano2){
        return rr < ano2.rr;
    }
}k[MAXN];
int tp =0 ;
void solve()
{
    scanf("%d%d%d%lf",&n,&m,&L,&V);
    L++;
    tp = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d",&d[i],&v[i],&a[i]);
        d[i]++;
    }

    for(int i = 1; i <= m; i++){
         scanf("%d",&p[i]);
         p[i]++;
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == 0){
            if(v[i] > V) l[i] = d[i],r[i] = L;//yi zhi chao su
            else l[i] = -1,r[i] = -1;
        }
        if(a[i] > 0){
            if(v[i] > V) l[i] = d[i],r[i] = L;
            else{
                long long cnt = min(cal(d[i],v[i],a[i]),L+1);
                l[i] = cnt,r[i] = L;
                if(l[i] > r[i]) l[i] = -1,r[i] = -1;
            }
        }
        if(a[i] < 0){
            if(v[i] <= V) l[i] = -1,r[i] = -1;
            else{
                long long cnt = min(cal(d[i],v[i],a[i]),L);
                l[i] = d[i],r[i] = cnt;
                if(l[i] > r[i]) l[i] = -1,r[i] = -1;
            }
        }
    }
    for(int i = 0; i <= L; i++) sum[i] = 0;
    for(int i = 1; i <= m; i++) sum[p[i]]++;
    for(int i = 1; i <= L; i++) sum[i] = sum[i-1] + sum[i];
    int over_speed = 0;
    for(int i = 1; i <= n; i++){
        if(l[i] == -1) continue;
        if(sum[r[i]] - sum[l[i]-1] != 0){
            over_speed++;
            k[++tp].ll = lower_bound(p+1,p+m+1,l[i]) - p;
            k[tp].rr = upper_bound(p+1,p+m+1,r[i]) - p;
            k[tp].rr --;
        }
    }
    sort(k+1,k+tp+1);
   // for(int i = 1; i <= tp; i++) cerr << k[i].ll <<" " << k[i].rr << endl;
    int cnt_max = 0;
    int lst = -1;
    for(int i = 1; i <= tp; i++){
        if(lst < k[i].ll){
            cnt_max++;
            lst = k[i].rr;
        }
    }
    printf("%d %d\n",over_speed,m - cnt_max);

}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t; scanf("%d",&t);
    while(t--) solve();

    return 0;
}
