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
const int NR=1e5+10;
int n, a[NR];
int main() {
    opf("duel");
    read(n);
    rps(i, 1, n)read(a[i]);
    sort(a+1, a+n+1);
    int ydn=1, ans=0;
    rps(i, 1, n) {
        while(ydn<n && a[ydn]<=a[i])ydn++;
        if(a[ydn]>a[i])ydn++;
        else ans++;
    }
    printf("%d\n", ans);
    return 0;
}
}
int main() {
    return cszhpdx::main();
}