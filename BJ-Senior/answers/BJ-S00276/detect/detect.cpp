#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e5 + 5;

int T,n,m,len,vmax;
int ans;
int d[N],a[N],v0[N],p[N];
struct Node{
    int l,r;
} can[N];

bool cmp(Node x,Node y){
    return x.r < y.r;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    scanf("%d",&T);
    while(T--){
        ans = 0;
        scanf("%d%d%d%d",&n,&m,&len,&vmax);
        for(int i = 1;i <= n;i++){
            scanf("%d%d%d",&d[i],&v0[i],&a[i]);
        }
        for(int i = 1;i <= m;i++){
            scanf("%d",&p[i]);
        }
        for(int i = 1;i <= n;i++){
            if(a[i] > 0){
                if(d[i] > p[m]){
                    can[i].l = can[i].r = -1;
                    continue;
                }
                // int tmin = ceil(1.0 * (vmax - v0[i]) / a[i]);
                // int s = v0[i] * tmin + ceil(0.5 * a[i] * tmin * tmin) + d[i];
                int s = 1.0 * (vmax * vmax - v0[i] * v0[i]) / 2 / a[i] + d[i];
                // cerr << i << ' ' << s << endl;
                if(s < p[m]){
                    ans++;
                    can[i].l = upper_bound(p + 1,p + m + 1,s) - p;
                    can[i].r = m;
                }else{
                    can[i].l = -1;
                    can[i].r = -1;
                    // cerr << i << endl;
                }
            }else if(a[i] == 0){
                if(v0[i] > vmax && d[i] <= p[m]){
                    ans++;
                    can[i].l = lower_bound(p + 1,p + m + 1,d[i]) - p;
                    can[i].r = m;
                }else{
                    can[i].l = -1;
                    can[i].r = -1;
                    // cerr << i << endl;
                }
            }else{
                if(d[i] > p[m]){
                    can[i].l = can[i].r = -1;
                    continue;
                }
                int fir = lower_bound(p + 1,p + m + 1,d[i]) - p;
                if(2 * a[i] * (p[fir] - d[i]) + v0[i] * v0[i] <= vmax * vmax){
                    can[i].l = -1;
                    can[i].r = -1;
                    // cerr << i << endl;
                }else{
                    int s = ceil(1.0 * (vmax * vmax - v0[i] * v0[i]) / 2 / a[i]) + d[i];
                    // cerr << i << ' ' << s << endl;
                    int sec = lower_bound(p + 1,p + m + 1,s) - p - 1;
                    ans++;
                    can[i].l = fir;
                    can[i].r = sec;
                }
            }
        }

        // for(int i = 1;i <= n;i++){
        //     cerr << can[i].l << ' ' << can[i].r << endl;
        // }
        sort(can + 1,can + n + 1,cmp);

        int st = 1,pos = 0,cnt = 0;
        for(int i = 1;i <= n;i++){
            if(can[i].r == -1) st++;
        }
        // cerr << st << endl;
        for(int i = st;i <= n;i++){
            if(can[i].l > pos){
                cnt++;
                pos = can[i].r;
            }
        }
        printf("%d %d\n",ans,m - cnt);

    }
}