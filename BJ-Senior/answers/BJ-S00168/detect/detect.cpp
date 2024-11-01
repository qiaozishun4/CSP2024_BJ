#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int ans = 0;
        int n,m;
        double L,V;
        cin >> n >> m >> L >> V;
        int flag[n+1][m+1];
        double d[n+1],v[n+1],a[n+1];
        for (int i =1 ; i <= n; i++){
            cin >> d[i] >> v[i] >> a[i];
        }
        double p[m+1];
        for (int i = 1; i <= m; i++){
            cin >> p[i];
        }
        for (int i = 1; i <= n; i++){
            bool f = false;
            for (int j = 1; j <= m; j++){
                if(p[j] >= d[i]){
                    double s = sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
                    if(s > V){
                        f= true;
                        flag[i][j] = 1;
                    }else{
                        flag[i][j] = 0;
                    }
                }else{
                    flag[i][j] = 0;
                }
            }
            if(f){
                ans++;
            }
        }
        cout <<ans <<" ";
        int num = 0;
        for (int c = m; c>= 1; c--){
                int k = 0;
            for (int i = 1; i <= n; i++){
                    bool f = false;
                for (int j = c; j <= m; j++){
                    if(flag[i][j]==1){
                        f = true;
                    }
                }
                if(f == true){
                    k++;
                }
            }
            if(k >= ans){
                num++;
            }
        }
        cout <<m-num;
        if(T!=0){
            cout << endl;
        }

    }
    return 0;
}
