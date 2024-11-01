#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t, n;
    cin >> t;
    while(t >= 0){
        t--;
        cin >> n;
        if(n % 7 == 0){
            n = n - 2;
            cout << 1 << endl;
            if(n % 6 == 1){
                for(int i = 1; i < n / 6; i++)
                    cout << 0 << endl;
                cout << 0 << endl;
            }
            else
                for(int i = 1; i <= n / 6; i++)
                    cout << 0 << endl;
        }
    }
    return 0;
}