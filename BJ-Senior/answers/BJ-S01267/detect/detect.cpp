#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

long double a[N], v[N], d[N], p[N];

int x[N], y[N];

bool vis[N];

struct node{
    int l, r, tmax, tag;
}tree[N * 4];

void build(int i, int l, int r){
    tree[i].l = l; tree[i].r = r; tree[i].tmax = 0; tree[i].tag = 0;
    if(l == r){
        return ;
    }
    int mid = l + r >> 1;
    build(i << 1, l, mid); build(i << 1 | 1, mid + 1, r);
}

void pushdown(int i){
    if(tree[i].tag != 0){
        tree[i << 1].tmax += tree[i].tag; tree[i << 1 | 1].tmax += tree[i].tag;
        tree[i << 1].tag += tree[i].tag; tree[i << 1 | 1].tag += tree[i].tag;
        tree[i].tag = 0;
    }
}

void add(int i, int l, int r, int k){
    if(tree[i].l >= l && tree[i].r <= r){
        tree[i].tmax += k; tree[i].tag += k; return ;
    }
    pushdown(i);
    int mid = tree[i].l + tree[i].r >> 1;
    if(l <= mid) add(i << 1, l, r, k);
    if(r >= mid + 1) add(i << 1 | 1, l, r, k);
    tree[i].tmax = max(tree[i << 1].tmax, tree[i << 1 | 1].tmax);
}

int find(int i){
    if(tree[i].l == tree[i].r) return tree[i].l;
    pushdown(i);
    if(tree[i << 1].tmax == tree[1].tmax) return find(i << 1);
    else return find(i << 1 | 1);
    tree[i].tmax = max(tree[i << 1].tmax, tree[i << 1 | 1].tmax);
} 

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int n, m, l;
        long double V;
        cin >> n >> m >> l >> V;
        for(int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
        for(int i = 1; i <= m; i++) cin >> p[i];
        int cnt = 0, k = 0, c = 0, cc = 0, maxl = -1;
        for(int i = 1; i <= n; i++){
            if(a[i] >= 0){
				c++;
				if(p[m] < d[i]) continue;
				long double tmp = v[i] * v[i] + 2 * a[i] * (p[m] - d[i]);
				tmp = sqrt(tmp);
				if(tmp <= V) continue;
                int l = 1, r = m, tmpl = m + 1;
                while(l <= r){
                    int mid = l + r >> 1;
                    if(p[mid] < d[i]) l = mid + 1;
                    long double tmp = sqrt(v[i] * v[i] + 2 * a[i] * (p[mid] - d[i]));
                    if(tmp > V) r = mid - 1, tmpl = min(tmpl, mid);
                    else l = mid + 1;
                }
                if(tmpl != m + 1){
                    cnt++;
                    maxl = max(maxl, tmpl);
                }
            }else if(a[i] < 0){
                int pp = lower_bound(p + 1, p + m + 1, d[i]) - p;
                if(p[pp] < d[i]) continue;
                else{
                    long double tmp = v[i] * v[i] + 2 * a[i] * (p[pp] - d[i]);
                    if(tmp <= 0) continue;
                    tmp = sqrt(tmp);
                    if(tmp > V) x[++cc] = pp;
                    else continue;
                    int l = pp, r = m, ansr = pp;
                    while(l <= r){
                        int mid = l + r >> 1;
                        long double tmp = v[i] * v[i] + 2 * a[i] * (p[mid] - d[i]);
                        if(tmp <= 0) r = mid - 1;
                        tmp = sqrt(tmp);
                        if(tmp > V) l = mid + 1, ansr = mid;
                        else r = mid - 1;
                    }
                    y[cc] = ansr; cnt++;
                }
            }
        }
        if(c == n){
			if(cnt != 0)cout << cnt << " " << m - 1 << endl;
            if(cnt == 0)cout << cnt << " " << m << endl;
            continue;
		}
        build(1, 1, m);
        
        for(int i = 1; i <= cc; i++){
            //cout << x[i] << " " << y[i] << endl;
            add(1, x[i], y[i], 1);
            vis[i] = false;
        }
        int ans = 0, f = 0;
        while(tree[1].tmax != 0){
            int tmp = find(1);
            //cout << tmp << endl;
            for(int i = 1; i <= cc; i++){
                if(tmp >= x[i] && tmp <= y[i] && !vis[i]) add(1, x[i], y[i], -1), vis[i] = true;
            }
            //cout << tree[1].tmax << endl;
            ans++;
        }
        cout << cnt << " " << m - ans << endl;
    }
}
