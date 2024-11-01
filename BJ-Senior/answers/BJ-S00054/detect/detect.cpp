#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3005;
typedef long long ll;

const int MAXL = 1000005;
int tree[MAXL << 4];
int mark[MAXL << 4];
void add(const int p, const int l, const int r, const int L, const int R, const int d);
int querry(const int p, const int l, const int r, const int L, const int R);

int chck[1000005];
bool ched[MAXN];
int pnt[1000005];
int que[MAXN];
int T, n, m;
ll L, V;
ll d, v, a;
ll l[MAXN], r[MAXN];
int p;

bool cmp(vector<int> a, vector<int> b){
    return a.size() >b.size();
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        cin >> n >> m >> L >> V;
        memset(tree, 0, sizeof tree);
        memset(mark, 0, sizeof mark);
        memset(pnt, 0, sizeof pnt);
        memset(ched, 0, sizeof ched);
        memset(que, 0, sizeof que);
        for(int i = 1; i <= n; i ++){
            cin >> d >> v >> a;
            double len;
            if(a) len = double(V * V - v * v) / double(2 * a);
            int lnr = int(len) + bool(len - int(len));
            int lnl = int(len);
            if(v > V){
                l[i] = d;
                if(a >= 0)
                    r[i] = L+1;
                else
                    r[i] = min(d + lnr, L+1);
            }else{
                if(a > 0 && d + lnl <= L+1)
                    l[i] = d + lnl, r[i] = L+1;
                else l[i] = -1, r[i] = -1;
            }
            --r[i];
            add(1, 0, L, l[i], r[i], 1);
            //cout << l[i] << ' ' << r[i] << endl;
        }
        for(int i = 1; i <= m; i ++){
            cin >> p;
            pnt[p] = i;
        }
        for(int i = 0; i <= L; i ++)
            chck[i] = chck[i-1] + (bool)pnt[i];
        int ans = 0;
        vector<int> acb[MAXN];
        for(int i = 1; i <= n; i ++){
            if(chck[r[i]] - chck[max(l[i]-1, 1ll * 0)])
                ++ans;
            for(int j = l[i]; j <= r[i]; j ++)
                if(pnt[j]) acb[pnt[j]].push_back(i);
        }
        cout << ans << ' ';
        ans = 0;
        sort(acb+1, acb+m+1, cmp);
        for(int i = 1; i <= m; i ++){
                //cout << i << ' ';
            bool flag = true;
            for(auto item: acb[i]){
                //cout << item << ' ';
                if(!ched[item])
                    flag = false;
                ched[item] = 1;
            }
            if(acb[i].size() == 0 || flag){
                ++ans;
            }
            //cout << endl;
        }
        //cout << '\n';
        cout << ans << '\n';

    }
    return 0;
}

void push_down(const int p, const int len1, const int len2){
    mark[p << 1] += mark[p];
    mark[p << 1 | 1] += mark[p];
    tree[p << 1] += mark[p] * len1;
    tree[p << 1 | 1] += mark[p] * len2;
    mark[p] = 0;
    return;
}

void add(const int p, const int l, const int r, const int L, const int R, const int d){
    if(r < L || R < l)
        return;
    //cout << l << ' ' << r << endl;
    if(L <= l && r <= R){
        tree[p] += d * (r - l + 1);
        mark[p] += d;
        return;
    }
    int mid = (l + r) >> 1;
    push_down(p, mid - l+1, r - mid);
    add((p << 1), l, mid, L, R, d);
    add((p << 1 | 1), mid+1, r, L, R, d);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
    return;
}

int querry(const int p, const int l, const int r, const int L, const int R){
    if(r < L || R < l)
        return 0;
    if(L <= l && r <= R)
        return tree[p];
    int mid = (l + r) >> 1;
    push_down(p, mid - l+1, r - mid);
    return querry((p << 1), l, mid, L, R) + querry((p << 1 | 1), mid+1, r, L, R);
}


