#include<bits/stdc++.h>
using namespace std;
#define rps(i, b, e) for(int i=(b);i<=(e);i++)
#define prs(i, e, b) for(int i=(e);i>=(b);i--)
#define rpg(i, g, x) for(int i=g.head[x];i;i=g.e[i].nxt)
#define mem(a, x) memset(a, x, sizeof(a))
#define opf(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
namespace cszhpdx {
template<class T>
void read(T &x) {
    x=0;
    bool f=false;
    char c=getchar();
    while(!isdigit(c))f|=(c=='-'), c=getchar();
    while(isdigit(c))x=x*10+(c-'0'), c=getchar();
    if(f)x=-x;
}
const int NR=1e5+10, MR=1e5+10;
typedef pair<int, int> range;
const range NU=make_pair(-1, -1);
int n, m, L, V, sct, tct, p[MR];
range s[NR], t[NR];
range gtrng(int d, int v, int a) {
    if(a>0) {
        if(v>V)return make_pair(d, L);
        int l=d+((V*V-v*v)/(2*a))+1;
        if(l>L)return NU;
        return make_pair(l, L);
    }
    if(a==0) {
        if(v>V)return make_pair(d, L);
        return NU;
    }
    if(a<0) {
        if(v<=V)return NU;
        a=-a;
        return make_pair(d, d+((v*v-V*V+2*a-1)/(2*a))-1);
    }
}
inline range jiao(range x, range y) {
    range res=make_pair(max(x.first, y.first), min(x.second, y.second));
    if(res.first>res.second)return NU;
    return res;
}
void work() {
    read(n), read(m), read(L), read(V);
    sct=tct=0;
    rps(i, 1, n) {
        int d, v, a;
        read(d), read(v), read(a);
        s[++sct]=gtrng(d, v, a);
        if(s[sct]==NU)sct--;
    }
    // rps(i, 1, sct)printf("[%d,%d]\n", s[i].first, s[i].second);
    rps(i, 1, m)read(p[i]);
    p[0]=-1, p[m+1]=L+1;
    sort(s+1, s+sct+1);
    int ima=1;
    rps(i, 1, sct) {
        while(ima<=n && p[ima]<s[i].first)ima++;
        if(s[i].second>=p[ima] && p[ima]>=s[i].first)
            t[++tct]=s[i], t[tct].first=ima;
    }
    printf("%d ", tct);
    rps(i, 1, tct)t[i].second=upper_bound(p+1, p+m+1, t[i].second)-p-1;
    sort(t+1, t+tct+1);
    // rps(i, 1, tct)printf("[%d,%d]\n", t[i].first, t[i].second);

    int least=0;
    range rima=NU;
    rps(i, 1, tct)if(i==1 || t[i-1].first!=t[i].first) {
        range r=jiao(rima, t[i]);
        if(r==NU)rima=t[i], least++;
        else rima=r;
    }
    printf("%d\n", m-least);
}
int main() {
    opf("detect");
    int T;read(T);
    while(T--)work();
    return 0;
}
}
int main() {
    return cszhpdx::main();
}