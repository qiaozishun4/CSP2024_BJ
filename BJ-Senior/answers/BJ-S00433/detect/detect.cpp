#include<iostream>
#include<climits>
//#define test
using namespace std;
int T;
int n, m;
int L;
int limitv;
const int N = 100010;
int d[N];
double d_in_limitv[N];
int cnt = 0;
int v[N];
int a[N];
int p[N];
double d_start[N];
double d_end[N];
bool carf[N] = {false};
int ans_n = 0;
int ans_p = 0;
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    for(int o = 1; o <= T; o++){
        ans_n = 0;
        ans_p = 0;
        cin >> n >> m >> L >> limitv;
        for(int i = 1; i <= n; i++){
            cin >> d[i] >> v[i] >> a[i];
            #ifdef test
            cout << d_start[i] << " " << d_end[i] << endl;
            #endif
        }
        
        for(int i = 1; i <= m; i++){
            cin >> p[i];
        }
        for(int i = 1; i <= n; i++){
            if(v[i] > limitv && d[i] <= p[m]){
                ans_n++;
            }else if(v[i] == limitv && a[i] > 0){
                if(d[i] < p[m]){
                    ans_n++;
                }
            }else if(v[i] < limitv && a[i] > 0){
                if(d[i] + (limitv * limitv - v[i] * v[i]) * 1.000 / (2 * a[i] * 1.000) < p[m]){
                    ans_n++;
                }
            }
        }
        if(ans_n == 0){
            ans_p = m;
        }else{
            ans_p = m - 1;
        }
        cout << ans_n << " " << ans_p << endl;
    }
    return 0;
}