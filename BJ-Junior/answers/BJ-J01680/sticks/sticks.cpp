#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int n;
        cin >> n;
        if(n % 7 == 0){
            int m = n/7;
            for (int j = 0; j < m; j++){
                cout << "8";
            }
            cout << endl;
        }
        else if (n % 7 == 1){
            int m = (n-1)/7 - 1;
            cout << "10";
            for (int j = 0; j < m; j++){
                cout << "8";
            }
            cout << endl;
        }
        else if (n == 1) cout << -1;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
