#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        int d[100001], v[100001], a[100001], p[100001];
        bool rd[1000001] = {0};
        for(int i = 0;i < n;i++){
            cin >> d[i] >> v[i] >> a[i];
        }
        for(int i = 0;i < m;i++){
            cin >> p[i];
            rd[p[i]] = true;
        }
        sort(p, p + m);
        int sum1 = 0, sum2 = 0;
        vector<int> v[100001];
        for(int i = 0;i < n;i++){
            int t = 0;
            int dir = d[i], sp = v[i];
            while(dir < L && sp > 0){
                if(rd[dir]){
                    v[i][t] = sp;
                    t++;
                    if(sp > V){
                        sum1++;
                        break;
                    }
                }
                int s = sp * 1 + 0.5 * a[i] * (1 * 1);
                sp = sqrt(sp * sp + 2 * a[i] * s);
                dir += s;
            }
        }
        cout << sum1 << ' ';
        bool f = false;
        bool cs[100001] = {0};
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(v[j][i] > V && !cs[j]){
                    cs[j] = true;
                    f = true;
                    break;
                }
            }
            if(!f){
                m--;
            }
        }
        cout << m << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
