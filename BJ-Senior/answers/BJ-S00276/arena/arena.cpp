#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 5;

int n,m,T;
int ans,sum;
int a0[N],a[N],b[4],c[N];
vector<int> d[N << 1];
int tr_d[N << 2],tr_id[N << 2],tr_wn[N << 2];
bool flag = 1;

void dfs(int x,int i,int id){
    if(x == 1){
        tr_id[id] = i + 1;
        return;
    }
    tr_d[id] = g[x][i];
    dfs(x - 1,i * 2,id * 2);
    dfs(x - 1,i * 2 + 1,id * 2 + 1);
}

int solve_you(int x,int k){
    if(k == 1) return tr_wn[x] = tr_id[x];

    int wlc = solve_you(x * 2,k - 1);
    int wrc = solve_you(x * 2 + 1,k - 1);

    if(!wlc || !wrc) return tr_wn[x] = (wlc | wrc);

    if(tr_d[x] == 0){
        if(a[wlc] >= k) return tr_wn[x] = wlc;
        return tr_wn[x] = wrc;
    }else{
        if(a[wrc] >= k) return tr_wn[x] = wrc;
        return tr_wn[x] = wlc;
    }
}

int find(int now,int dest,int id){
    if(now + dest == k){
        return tr_wn[id];
    }
    return find(now + 1,dest,id * 2);
}

int solve_wu(int now,int dest,int id,int limit,int op){
    if(now == k){
        if(tr_id[id] > limit) sum += op * tr_id[id];
        return tr_id[id];
    }
    int wlc = solve_wu(now + 1,dest,id * 2,limit,op);
    if(wlc > limit) solve_wu(now + 1,dest,id * 2,limit,1);
    int wrc = solve_wu(now + 1,dest,id * 2 + 1,limit,op);
    if(wrc > limit) solve_wu(now + 1,dest,id * 2,limit,1);

    if(wlc > limit || wrc > limit) return max(wlc,wrc);
    if(tr_d[id] == 1 && a[wrc] ==  && a[wlc] > now - dest) return wlc;
    if(tr_d[id] == 0 && a[wrc] > now - dest) return wrc;
    return 1e9;
}

int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a0[i]);
    }
    for(int i = 1;i <= m;i++){
        scanf("%d",&c[i]);
    }
    sort(c + 1,c + m + 1);
    int k = 0;
    while((1 << k) < n) k++;
    char endline;
    // cerr << k << endl;
    for(int i = 1;i <= k;i++){
        scanf("%c",&endline);
        // cerr << (1 << k - i + 1) << endl;
        for(int j = 0;j < (1 << k - i);j++){
            char ch;
            scanf("%c",&ch);
            d[i].push_back(ch - '0');
            if(ch == '1') flag = 0;
            // cerr << ch << ' ';
        }
        // cerr << i << endl;
    }

    dfs(k,0,1);

    scanf("%d",&T);
    while(T--){
        ans = 0;
        for(int i = 0;i < 3;i++){
            scanf("%d",&b[i]);
        }
        for(int i = 1;i <= n;i++){
            a[i] = a0[i] ^ b[i % 4];
        }
        solve_you(1,k);

        int kk = 0;
        for(int i = 1;i <= m;i++){
            while((1 << kk) < c[i]) kk++;
            ans ^= tr_wn[1 << (k - kk)];
        }
        cout << ans << endl;
    }
}