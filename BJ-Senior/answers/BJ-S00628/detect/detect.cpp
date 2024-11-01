#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 +5;

struct car{
    int cs = -1;
    bool out = 0;
}C[100001];

int main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out", "w", stdout);
    int y;
    cin >>y;
    for(int k = 0; k <y; k ++) {
        int n, m, l, v, chao = 0;
        cin >>n >>m >>l >>v;
        int d[100001];
        int shortt = 1e5, longg = 0;
        for(int i = 0; i < n; i ++) {
            float di, a, vi;
            cin >>di >>a >>vi;
            if((v *v - vi * vi) / (2 * a) < l - di){
                C[i].cs = (v *v - vi * vi) / (2 * a);
                chao ++;
                if((v *v - vi * vi) / (2 * a) < shortt){
                    shortt = (v *v - vi * vi) / (2 * a);
                }
                if((v *v - vi * vi) / (2 * a) > longg){
                    longg = (v *v - vi * vi) / (2 * a);
                }
            }else {
                C[i].out = 1;
            }
        }
        cout <<chao <<" ";
        int close = 0;
        int dmin = 1e5, dmax = 0, uppp, dowwwn;
        for(int i = 0; i < m; i ++){
            cin >> d[i];
            if(d[i] < shortt && d[i] > dmax){
                dmax = d[i];
                dowwwn = d[i];
            }
            if(d[i] < longg && d[i] > shortt&&d[i] > dmin){
                dmin = d[i];
                uppp = d[i];
            }
        }
        for(int i = 0; i < m; i ++) {
            if(d[i] > longg){
                close ++;
            }
            if(d[i] < dowwwn){
                close ++;
            }
            if(d[i] < uppp && d[i] > shortt){
                close ++;
            }
        }
        cout << close <<endl;
    }
    return 0;
}
