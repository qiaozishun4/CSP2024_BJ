#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define eps 1e-9
#define endl '\n'
using namespace std;

int compare(ld a, ld b) {
    if(b-a>eps) return -1;
    else if(fabs(b-a)<=eps) return 0;
    return 1;
}

struct node {
    ld l,r;
} segments[100010];

struct node1 {
    ll l,r;
    bool operator<(const node1 &T) const {
        if(l==T.l) {
            return r<T.r;
        }
        else return l<T.l;
    }
} q[100010];

ll n, m, L, vmax;
ll tot, cnt, ans;
ll pos[100010];

void buildSegments(ll d, ll v, ll a) {
    if(a>0) {
        ld l=(vmax*vmax-v*v)*1.0/2/a+d;
        if(compare(l, L)<=0) {
            segments[++cnt]={max(l+eps*10, (ld)d),L};
            // printf("%.9Lf %.9Lf\n", segments[cnt].l, segments[cnt].r);
        }
        // else puts("OK");
    }
    else if(a<0) {
        if(v>vmax) {
            segments[++cnt]={d,min((vmax*vmax-v*v)*1.0/2/a+d-eps*10, L*1.0)};
            // printf("%.9Lf %.9Lf\n", segments[cnt].l, segments[cnt].r);
        }
        // else puts("OK");
    }
    else {
        if(v>vmax) {
            segments[++cnt]={d,L};
            // printf("%.9Lf %.9Lf\n", segments[cnt].l, segments[cnt].r);
        }
        // else puts("OK");
    }
    
}

void check(ll i) {
    ld l = segments[i].l, r = segments[i].r;
    ll L1=1, R1=m, L2=1, R2=m;
    while(L1<R1) {
        ll mid = (L1+R1)>>1;
        if(compare(pos[mid], l)>=0) R1=mid;
        else L1=mid+1;
    }
    while(L2<R2) {
        ll mid = ceil((L2+R2)/2.0);
        if(compare(pos[mid], r)<=0) L2=mid;
        else R2=mid-1;
    }
    // cout<<L1<<" "<<L2<<endl;
    if(pos[L2]>r || pos[L1]<l || L1>L2) {
        return;
    }
    q[++tot]={L1,L2};
}

void solve() {
    cin>>n>>m>>L>>vmax;
    tot=cnt=ans=0;
    for(int i=1;i<=n;i++) {
        ll d,v,a;
        cin>>d>>v>>a;
        buildSegments(d,v,a);
    }
    for(int i=1;i<=m;i++) {
        cin>>pos[i];
    }
    for(int i=1;i<=cnt;i++) {
        check(i);
    }
    sort(q+1, q+tot+1);
    ll minend=q[1].r;
    for(int i=2;i<=tot;i++) {
        if(q[i].l>minend) {
            ans++;
            ll L1=1, R1=tot;
            while(L1<R1) {
                ll mid = (L1+R1)>>1;
                if(compare(q[mid].l, minend)>0) R1=mid;
                else L1=mid+1;
            }
            minend = q[L1].r;
            i=L1;
        }
        else {
            minend=min(minend, q[i].r);
        }
    }
    cout<<tot<<' '<<(tot==0?m:m-ans-1)<<endl;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}

// Last Updated UTC+8 2024/10/26 SAT 17:32
// 100pts O(Tnlogn)