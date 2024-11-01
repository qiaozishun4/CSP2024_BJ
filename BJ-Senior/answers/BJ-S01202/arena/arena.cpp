#include <bits/stdc++.h>
using namespace std;
int n, m, t, a[100005], c[100005], x[5], cnt = 0;
char k[35][40];
struct nod{
    int id, a;
} p[100005];
int main(){
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> c[i];
    }
    int f = 1, z = 0;
    while(f < n){
        f *= 2;
        z++;
    }
    while(f > 1){
        cin >> k[++cnt];
        f /= 2;
    }
    cin >>t;
    while(t--){
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        long long ans = 0;
        for(int l = 1; l <= m; l++){
            int f = 1, tmp = 0;
            while(f < c[l]){
                f *= 2;
                tmp++;
            }
            for(int i = 1; i <= f; i++){
                p[i].a = a[i] ^ x[i % 4];
                p[i].id = i;
                //cout << p[i].a << " ";
            }
            //cout << endl;
            //cout << f << " " << tmp << endl;
            if(tmp == 0){
                ans += p[1].id;
                //cout << p[1].id << "%%%%\n";
                continue;
            }
            for(int i = 1; i <= tmp; i++){
                for(int j = 1; j <= f; j += 2){
                        //cout << l << " " << i << " " << j << " " << (k[i][(j + 1 >> 1) - 1] == '0')<< endl;
                    if(k[i][(j + 1 >> 1) - 1] == '0'){
                        if(p[j].a < p[j + 1].a){
                            if(p[j].a >= i){
                                p[(j + 1) / 2] = p[j];
                            } else{
                                p[j + 1 >> 1] = p[j + 1];
                            }
                        } else{
                            if(p[j + 1].a >= i){
                                p[(j + 1) / 2] = p[j + 1];
                            } else{
                                p[j + 1 >> 1] = p[j];
                            }
                        }
                    } else{
                        if(p[j].a > p[j + 1].a){
                                //cout << "#";
                            if(p[j].a >= i){
                                p[(j + 1) / 2] = p[j];
                            } else{
                                p[j + 1 >> 1] = p[j + 1];
                            }
                        } else{
                            if(p[j + 1].a >= i){
                                p[(j + 1) / 2] = p[j + 1];
                            } else{
                                p[j + 1 >> 1] = p[j];
                            }
                        }
                    }
                }
                f /= 2;
            }
            //cout << p[1].id << endl;
            ans = ans ^ ((long long) l * p[1].id);
        }
        cout << ans << endl;
    }
    return 0;
}
