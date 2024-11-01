#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,a[] = {0,-1,1,7,4,2,6,8,10,18,40,20,28,68,88,108,188};
//           0  1 2 3 4 5 6 7  8  9 10 11 12 13 14  15  16
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1) cout << "-1\n";
        else if(n % 7 == 0){
            int k = n / 7;
            for(int i = 1; i <= k; i++){
                cout << 8;
            }
            cout << "\n";
        }
        else if(n % 7 == 1){
            int k = n / 7;
            k--;
            cout << 10;
            for(int i = 1; i <= k; i++){
                cout << 8;
            }
            cout << "\n";
        }else if(n % 7 == 2){
            int k = n / 7;
            k--;
            cout << 18;
            for(int i = 1; i <= k; i++){
                cout << 8;
            }
            cout << "\n";
        }else if(n % 7 == 3){
            int k = n / 7;
            k--;
            cout << 40;
            for(int i = 1; i <= k; i++){
                cout << 8;
            }
            cout << "\n";
        }else if(n % 7 == 4){
            int k = n / 7;
            k--;
            cout << 20;
            for(int i = 1; i <= k; i++){
                cout << 8;
            }
            cout << "\n";
        }else if(n % 7 == 5){
            int k = n / 7;
            k--;
            cout << 28;
            for(int i = 1; i <= k; i++){
                cout << 8;
            }
            cout << "\n";
        }else if(n % 7 == 6){
            int k = n / 7;
            k--;
            cout << 68;
            for(int i = 1; i <= k; i++){
                cout << 8;
            }
            cout << "\n";
        }
    }
    return 0;
}
