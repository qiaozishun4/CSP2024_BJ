#include<bits/stdc++.h>//TIM!!!
#define int long long
using namespace std;
struct node{
    int l, r;
};
long long n, m, L, V;
int totask, totp;
node p[100010];
node ask[100010];
int mntor[100010];
int sumn[1000010];
int UP(int x, int y) {
    return (x+y-1)/y;
}
void add(int l, int r) {
    r = min(r, L);
    if(l>r) return;
    ++totask;
    ask[totask] = (node){l, r}; 
}
bool cmp(node s, node t) {
    if(s.r==t.r) return s.l < t.l;
    return s.r < t.r;
}
int findf(int l, int r) {
    if(l==0) return sumn[r];
    return sumn[r]-sumn[l-1];
}
void solve() {
    totask = totp = 0;
    memset(sumn, 0, sizeof(sumn));
    cin >> n >> m >> L >> V;
    for(int i=1; i<=n; ++i) {
        int d, v, a;
        cin >> d >> v >> a;
        if(a>0) {
            if(v>V) add(d, L);
            else if((V*V-v*v)%(2*a)==0) {
                add(max(d, d+(V*V-v*v)/(2*a)+1), L);
            }else {
                add(max(d, d+UP(V*V-v*v, 2*a)), L);
            }
        }else if(a<0) {
            if(v<=V) continue;
            if((-V*V+v*v)%(-2*a)==0) {
                add(d, d+(-V*V+v*v)/(-2*a)-1);
            }else {
                add(d, d+(-V*V+v*v)/(-2*a));
            }
        }else {
            if(v>V) add(d, L);
        }
    }
    //for(int i=1; i<=totask; ++i) cout << ask[i].l << ' ' << ask[i].r << '\n';
    //cout << "qqq\n";
    for(int i=1; i<=m; ++i) {
        cin >> mntor[i];
        ++sumn[mntor[i]];
    }
    for(int i=1; i<=L; ++i) {
        sumn[i] += sumn[i-1];
    }
    //for(int i=0; i<=L; ++i) cout << sumn[i] << ' ';
    //cout << "qqq\n";
    int ans1 = 0;
    for(int i=1; i<=totask; ++i) {
        if(findf(ask[i].l, ask[i].r)>0) {
            ++ans1;
            ++totp;
            p[totp] = ask[i];
        }
    }cout << ans1 << ' ';
    sort(p+1, p+totp+1, cmp);
    int R = -1, ans2 = 0;
    for(int i=1, j=0; i<=totp; ++i) {
        if(R>=p[i].l) continue;
        while(j<m && mntor[j+1]<=p[i].r) ++j; 
        ++ans2, R = mntor[j];
    }
    cout << m-ans2 << '\n';
}
signed main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0; 
}