#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 10005 ;
 
int main(){
    freopen("detect.in" , "r" , stdin) ;
    freopen("detect.out" , "w" , stdout) ;
 
    int T ,n ,m ,L ,V ,d[MAXN] ,v[MAXN] ,a[MAXN] ,p[MAXN] ,sum = 0 , num = 0 ;
 
    for (int x = 1 ; x <= T ; x++ ) {
        cin >> T >> n >> m >> L >> V ;
        for (int i = 0 ; i < n ; i++ ) cin >> d[i] >> v[i] >> a[i] ;
        for (int i = 0 ; i < m ; i++ ) cin >> p[i] ;
 
        for (int i = 0 ; i < n ; i++ ) {
            for (int j = 0 ; j < m ; j++ ) {
                if (d[i] > p[j]) continue;
                v[i] = sqrt(v[i]*v[i] + 2 * a[i] * (p[sum] - d[i]) ) ;
                sum++ ;
                if (v[i] > V) {
                    num++ ;
                    break ;
                }
            }
        }
 
        cout << num << num-1 << endl ;
        num = 0 ;
        sum = 0 ;
        for (int i = 0 ; i < MAXN ; i++ ) {
            d[i] = 0;
            v[i] = 0;
            a[i] = 0;
            p[i] = 0;
        }
    }
    return 0;
}