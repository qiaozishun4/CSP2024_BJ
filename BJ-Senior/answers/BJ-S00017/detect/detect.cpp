#include<bits/stdc++.h>
using namespace std;

int n, m, l, v;

const int N = 1e5 + 5, M = 1e5 + 5;
double d[N];
struct Car{
        int v;
        int a;
}c[N];

int p[M];

int solve1(){
        double xfinal[N];
        int cnt = 0;
        for(int i = 0; i < n; i++){
                xfinal[i] = d[i] + ((pow(v, 2) - pow(c[i].v, 2)) / (2 * c[i].a));
        }
        for(int i = 0; i < n; i++){
                if(c[i].a > 0 && p[m - 1] >= 0 && p[m - 1] > xfinal[i]){
                        cnt++;
//                      cout << i << " big" <<  c[i].a << endl;
                }else if(c[i].a < 0 && p[0] >= 0 && p[0] < xfinal[i]){
                        cnt++;
//                      cout << i << " small" << endl;
                }else if(c[i].v > v){
                        cnt++;
                }
        }
        return cnt;
}

int main(){
      freopen("detect.in", "r", stdin);
      freopen("detect.out", "w", stdout);
        int t;
        cin >> t;
        while(t--){
                memset(d, 0, sizeof(d));
                int cnt2 = 0;
                cin >> n >> m >> l >> v;
                for(int i = 0; i < n; i++) cin >> d[i] >> c[i].v >> c[i].a;
                for(int i = 0; i < m; i++) cin >> p[i];
                cout << solve1() - 1 << " ";

                int ans = solve1();
                for(int i = 0; i < m; i++){
                        int t = p[i];
                        p[i] = -1;
                        if(solve1() == ans) cnt2++;
                        else p[i] = t;
                }
                cout << cnt2 - 1 << endl;

        }

     fclose(stdin);
      fclose(stdout);
        return 0;
}
