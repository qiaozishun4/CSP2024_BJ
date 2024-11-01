#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,a[] = {0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688};
main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--){
        int x;
        cin >> x;
        if (x < 21){
            cout << a[x] << "\n";
        }else if (x % 7 == 0){
            int eights = x / 7;
            for (int i = 1;i <= eights;i++) cout << "8";
            cout << "\n";
        }else if (x % 7 == 1){
            int eights = (x - 8) / 7;
            cout << "10";
            for (int i = 1;i <= eights;i++) cout << "8";
            cout << "\n";
        }else if (x % 7 == 2){
            int eights = (x - 2) / 7;
            cout << "1";
            for (int i = 1;i <= eights;i++) cout << "8";
            cout << "\n";
        }else if (x % 7 == 3){
            int eights = (x - 17) / 7;
            cout << "200";
            for (int i = 1;i <= eights;i++) cout << "8";
            cout << "\n";
        }else if (x % 7 == 4){
            int eights = (x - 11) / 7;
            cout << "20";
            for (int i = 1;i <= eights;i++) cout << "8";
            cout << "\n";
        }else if (x % 7 == 5){
            int eights = (x - 5) / 7;
            cout << "2";
            for (int i = 1;i <= eights;i++) cout << "8";
            cout << "\n";
        }else if (x % 7 == 6){
            int eights = (x - 6) / 7;
            cout << "6";
            for (int i = 1;i <= eights;i++) cout << "8";
            cout << "\n";
        }
    }
    return 0;
}