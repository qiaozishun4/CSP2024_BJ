#include <bits/stdc++.h>

using namespace std;
struct AA{
    long long bi,ui,ai;

}a[1000005];
long long h[1000005];
long long n,m,L,V;
long long T;
long long tot,tot2;
bool cmp(AA x,AA y){
    return x.bi > y.bi;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n>> m >> L >> V;
        long long b,u,aa;
        for(long long i = 1;i <= n;i++){
            cin >> b >> u >> aa;
            if(u > V){
                a[tot].ai = aa;
                a[tot].bi = b;
                a[tot].ui = u;
                tot++;
            }else if(u*u+(L-b)*2*aa > V*V){
                a[tot].ai = aa;
                a[tot].bi = b;
                a[tot].ui = u;
                tot++;
            }
        }
        for(long long i = 1;i <=m;i++){
                int o;
            cin >> o;
            h[i] = o;
        }
        int f = -1;
        int s = 0;
        for(long long i = 0;i <= tot;i++){
            for(long long j = 1;j <= m;j++){
                if(h[j] > a[i].bi){
                    if(a[i].ui*a[i].ui+(h[j]-a[i].bi)*2*a[i].ai > V*V){
                        s++;
                        break;
                    }
                }
            }
        }
        cout << s << ' ';
        cout << m-1;
    }
    return 0;
}
