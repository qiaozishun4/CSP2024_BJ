#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define Son (id<<1|son[id])

const int N = 100010;
const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> pii;
int top[N<<2], time[N<<2], winner[N<<2], l[N<<2], r[N<<2], R[N<<2];
bool son[N<<2];
int a[N], Id[N], n, m, K;

void getTime(int id = 1){
    if(l[id]==r[id]){
        time[id] = l[id];
        winner[id] = l[id];
        return;
    }
    getTime(id<<1);
    getTime(id<<1|1);
    if(winner[Son] <= n){
        if(a[winner[Son]] >= R[id]){
            time[id] = time[Son];
            winner[id] = winner[Son];
        }
        else{
            time[id] = max(time[id<<1], time[id<<1|1]);
            winner[id] = winner[Son^1];
        }
    }
    else{
        time[id] = max(time[id<<1], time[id<<1|1]);
        winner[id] = winner[Son];
    }
}

int when(int p){
    int id = Id[p];
    // printf("id=%d\n", id);
    int res = n+1;
    while(id != 1){
        // if(id)
        //     printf("%d->%d\n", id, top[id]);
        id = top[id];
        if(a[p] < R[id])
            res = min(res, p);
        if(a[winner[id^1]] >= R[id]+1)
            res = min(res, time[id^1]);
        if(id == 1) break;
        id >>= 1;
    }
    return res;
}

void buildtree(int id = 1, int ll = 1, int rr = K, int t = 1){
    top[id] = t;
    l[id] = ll;
    r[id] = rr;
    if(ll == rr){
        Id[ll] = id;
        R[id] = 0;
        return;
    }
    int mid = (ll + rr) >> 1;
    buildtree(id<<1, ll, mid, son[id]?(id<<1):t);
    buildtree(id<<1|1, mid+1, rr, son[id]?t:(id<<1|1));
    R[id] = R[id<<1]+1;
    return;
}

int ta[N], c[N], x[4];
pii w[N];
char s[N<<1];
ll ans[N];

int main(){
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", ta+i);
    for(int i = 1; i <= m; i++)
        scanf("%d", c+i);
    int tmp = n-1, log=0;
    while(tmp > 0){
        tmp>>=1;
        log++;
    }
    K = 1<<log;
    for(int i = 1; i <= log; i++){
        scanf("%s", s);
        for(int j = 0; j < (K>>i); j++)
            son[(K>>i)+j] = (s[j]=='1');
    }
    buildtree();
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d", x, x+1, x+2, x+3);
        for(int i = 1; i <= n; i++)
            a[i] = ta[i]^x[i&3];
        getTime();
        // printf("time=%d, winner=%d, R=%d\n", time[6], winner[6], a[winner[6]]);
        for(int i = 1; i <= n; i++){
            w[i].first = when(i);
            w[i].second = i;
        }
        // printf("checkpoint\n");
        sort(w + 1, w + n + 1);
        ans[0] = (ll)K*(ll)(K+1)/2ll;
        for(int i = 1, j = 1; i <= n; i++){
            ans[i] = ans[i-1];
            while(j <= n && w[j].first <= i){
                ans[i] -= w[j].second;
                j++;
            }
            // printf("%d, %d\n", i, j);
        }
        // for(int i = 1; i <= m; i++)
        //     printf("%lld ", ans[c[m]]);
        // printf("\n");
        ll ANS = 0;
        for(int i = 1; i <= m; i++)
            ANS ^= ((ll)i*(ll)ans[c[m]]);
        printf("%lld\n", ANS);
    }
    return 0;
}