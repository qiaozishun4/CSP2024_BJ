#include <bits/stdc++.h>
using namespace  std;
int T;
const int N = 1e5+5;
int d[N] , v[N] , a[N] , p[N] , f[N];
bool isfast(int d , int v , int a , int l , int V)
{
    return sqrt(1.0*(v*v+2*a*(l-d)))>V;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> T;
    while(T--){
        int n , m , l , V ;
        cin >> n >> m >> l >> V;
        bool f=1;
        for(int i = 1; i <= n; i++){
            cin >> d[i]>>v[i]>>a[i];
            if(a[i]!=0)f=0;
        }
        int cnt = 0;
        for(int i = 1; i <= m; i++)cin >> p[i];
        if(f){
            for(int i = 1; i <= n; i++){
                if(v[i]>V&&d[i]<=p[m]){
                    cnt++;
                }
            }
            cout << cnt << " " << m-1<<endl;
        }
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
    }
    return 0;
}

