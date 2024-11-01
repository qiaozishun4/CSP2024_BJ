#include<bits/stdc++.h>
using namespace std;
int T, p[100010];
struct road{
    int d;
    int v;
    int a;
    int x;
}r[100010];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    memset(p,0,sizeof(p));
    cin >> T;
    while(T--){
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;i++){
            cin >> r[i].d >> r[i].v >> r[i].a;
        }
        for(int i = 1;i <= m;i++){
            cin >> p[i];
        }
        int cnt1 = 0;
        for(int i = 1;i<=n;i++){
            if(r[i].v > V && r[i].d <= p[m]) cnt1++;
        }
        if(m == 1) cout << cnt1 << " " << 0 << endl;
        else cout << cnt1 << " " << m-1 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
