#include<bits/stdc++.h>
using namespace std;
struct Car{
    int d, v, a;
}c[100001];
int n, m, L, V, p[100001];
namespace Sol1{
    bool check[50][50], box[50], isgood[50];
    inline bool checked(){
        for(int i = 1; i <= n; i++){
            bool flag = isgood[i];
            for(int j = 1; j <= m; j++){
                if(check[i][j]){
                    if(box[j]){
                        flag = true;
                    }
                }
            }
            if(!flag) return false;
        }
        return true;
    }
    inline void Solve(){
        memset(check, false, sizeof(check));
        memset(isgood, 0, sizeof(isgood));
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            bool flag = false;
            for(int j = 1; j <= m; j++){
                if(p[j] >= c[i].d) check[i][j] = ( c[i].v * c[i].v + 2 * c[i].a * (p[j]-c[i].d) > V * V );
                if(check[i][j]) flag = true;
            }
            if(flag) cnt++;
            else isgood[i] = true;
        }
        cout << cnt << " ";
        int ans = 0;
        for(int i = 0; i < (1<<m); i++){
            memset(box, 0, sizeof(box));
            int ccnt = 0;
            for(int j = m - 1; j >= 0; j--){
                if((1<<j) & i){
                    box[m-j] = true;
                    ccnt++;
                }
            }
            if(checked()) ans = max(ans, m-ccnt);
        }
        cout << ans << endl;
        return;
    }
}
namespace SolA{
    inline void Solve(){
        sort(p+1, p+1+m);
        int lstt = p[m], cnt = 0;
        for(int i = 1; i <= n; i++){
            if(c[i].d <= lstt && c[i].v > V){
                cnt++;
            }
        }
        if(cnt == 0){
            cout << 0 << " " << m << endl;
        }else{
            cout << cnt << " " << m - 1 << endl;
        }
        return;
    }
}
namespace SolB{
    inline void Solve(){
        sort(p+1, p+1+m);
        int lstt = p[m], cnt = 0;
        for(int i = 1; i <= n; i++){
            if(c[i].d <= lstt){
                int s = lstt - c[i].d;
                if(c[i].v * c[i].v + 2 * c[i].a * s > V * V){
                    cnt++;
                }
            }
        }
        if(cnt == 0){
            cout << 0 << " " << m << endl;
        }else{
            cout << cnt << " " << m - 1 << endl;
        }
        return;
    }
}
inline void Solve(){
    cin >> n >> m >> L >> V;
    bool A = true, B = true, C = true;
    for(int i = 1; i <= n; i++){
        cin >> c[i].d >> c[i].v >> c[i].a;
        if(c[i].a != 0) A = false;
        if(c[i].a <= 0) B = false;
        if(c[i].a >= 0) C = false;
    }
    for(int i = 1; i <= m; i++) cin >> p[i];
    if(n <= 20 && m <= 20){
        Sol1::Solve();
        return;
    }
    if(A){
        SolA::Solve();
        return;
    }
    if(B){
        SolB::Solve();
        return;
    }
    return;
}
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        Solve();
    }
    return 0;
}