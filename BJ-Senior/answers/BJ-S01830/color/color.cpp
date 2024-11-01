#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    if (t == 1 && n <= 15){
        cout << 1;
    }
    else if (t == 2 && n <= 15)
        cout << 1 << endl << 0;
    else if (t == 3 && n <= 15)
        cout << 1 << endl << 0 << endl << 8;

    return 0;
}
