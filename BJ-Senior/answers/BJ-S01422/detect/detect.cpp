#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >>t;
    while(t--){
        int n, m, l, v;
        cin >> n >> m>> l >>v;
        const int o = n;
        int d[o], w[o], a[o], b[o], k[o];
        for(int i = 0;i < n;i++){
            cin >> d[i]>> w[i]>> a[i];
        }
        const int x = m;
        int p[x], f[x][o];
        int ans1 = 0;
        for(int i = 0;i < m;i++){
            cin >> p[i];
            for(int j = 0;j < n;j++){
                b[i] = p[i]-d[i];
                int b1 = b[i];
                int a1 = a[i];
                int v1 = w[i];
                k[o] = sqrt(v1*v1+2*a1*b1);
                if(k[0]>v){
                    f[x][i]++;
                }
            }
        }
        for(int i = 0;i < n;i++){
            b[i] = p[m-1]-d[i];
            int b1 = b[i];
            int a1 = a[i];
            int v1 = w[i];
            k[o] = sqrt(v1*v1+2*a1*b1);
            if(k[0]>v){
                ans1++;
            }
        }
        int ans2 = 0;
        int h[o];
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                h[i]+=f[i][j];
            }
        }
        for(int i = 0;i < m;i++){
            int flag = 0;
            for(int j = 0;j< n;j++){
                if(f[i][j]==1&&h[j]==1){
                    flag = 1;
                }
            }
            if(flag == 0){
                for(int j = 0;j < n;j++){
                    if(f[i][j] == 1){
                        h[j]--;
                        ans2++;
                    }
                }
            }
        }
        cout << ans1 << " "<<ans2 <<endl;
    }
    return 0;
}
