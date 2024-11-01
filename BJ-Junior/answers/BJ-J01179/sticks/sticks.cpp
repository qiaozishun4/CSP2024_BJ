#include <bits/stdc++.h>
using namespace std;
int big[10] = {6,2,5,5,4,5,6,3,7,6},t,n,x;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while (t--){
        cin >> x;
        n = x;
        if (n == 1) cout << -1;
        else if (n <= 7){
            for (int i = 1;i < 10;i++)
                if (big[i] == n){
                    cout << i;
                    break;
                }
        }else{
            while (n != 0){
                if (n % 7 == 0){
                    for (int i = 1;i <= n / 7;i++)
                        cout << 8;
                    break;
                }
                if (n < 7){
                    for (int i = 0;i < 10;i++)
                        if (big[i] == n){
                            cout << i;
                            break;
                        }
                    break;
                }else if (n != x){
                    cout << 0;
                    n -= 6;
                }else{
                    int l = n % 7;
                    for (int i = 1;i < 10;i++)
                        if (big[i] >= l){
                            cout << i;
                            n -= big[i];
                            break;
                        }
                }
            }
        }
        cout << endl;
    }
    return 0;
}