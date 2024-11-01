#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int w[] = {6,2,5,5,4,5,6,3,7,6};
int T,n,f[N];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin >> T;
    while(T--){
        memset(f,0x3f,sizeof f);
        cin >> n;
        if(n <= 50){
            f[0] = 0;
            f[1] = 0x3f3f3f3f;
            f[2] = 1;
            f[3] = 7;
            f[4] = 4;
            f[5] = 2;
            f[6] = 6;
            f[7] = 8;
            for(int i = 0; i < 10; ++i){
                for(int j = w[i]; j <= n; ++j){
                    if(!i&&j==w[i]) continue;
                    f[j] = min(f[j],f[j-w[i]]*10+i);
                }

            }

            cout << (f[n]>=1e9? -1: f[n]) << endl;
        } else if(n%7==0){
            for(int i = 1; i <= n/7; ++i) cout << 8;
            cout << endl;
        } else if(n%7==1){
            cout << 10;
            for(int i = 1; i <= n/7-1; ++i) cout << 8;
            cout << endl;
        } else cout << -1 << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
