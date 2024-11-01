#include <bits/stdc++.h>
using namespace std;
int a[50] = {-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int tt;
    cin >> tt;
    while (tt--){
            int n;
        cin >> n;
        cout << a[n] << "\n";
    }

    return 0;
}

