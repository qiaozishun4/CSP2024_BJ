#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> T;
    while(T--){
        int n,a[105];
        int ys[105];
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        long long sum = 0;
        long long ans = 0;
        int nn=1;
        for(int i = 1; i <= n; i++) nn *= 2;
        for(int i =0; i < nn; i++){
            sum = 0;
            int ii = i;
            for(int j = n; j >= 1; j--){
                ys[j] = ii%2;
                ii /= 2;
            }
            int h=0,l=0;
            for(int j = 1; j <= n; j++){
                if(ys[j] == 1){
                    if(a[j] == a[l]) sum += a[j];
                    l=j;
                } else {
                    if(a[j] == a[h]) sum += a[j];
                    h=j;
                }
            }
            if(ans < sum) ans = sum;
        }
        cout << ans << endl;
        for(int i = 1; i <= n; i++) {ys[i] = 0;a[i] = 0;}
    }
    return 0;
}
