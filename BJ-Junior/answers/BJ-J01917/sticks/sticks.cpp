# include <bits/stdc++.h>
using namespace std;
//int a[10] = {6,2,5,5,4,5,6,3,7,6};

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        if (n % 7 == 0){
            for (int i=1;i<=n/7;i++){
                cout << '8';
            }
            cout << "\n";
        }
        if (n % 7 == 1){
            cout << 10;
            for (int i=1;i<=(n/7)-1;i++){
                cout << '8';
            }
            cout << "\n";
        }
        if (n % 7 == 2){
            cout << 18;
            for (int i=1;i<=(n/7)-1;i++){
                cout << '8';
            }
            cout << "\n";
        }
        if (n % 7 == 3){
            cout << 22;
            for (int i=1;i<=(n/7)-1;i++){
                cout << '8';
            }
            cout << "\n";
        }
        if (n % 7 == 4){
            cout << 20;
            for (int i=1;i<=(n/7)-1;i++){
                cout << '8';
            }
            cout << "\n";
        }
        if (n % 7 == 5){
            cout << 28;
            for (int i=1;i<=(n/7)-1;i++){
                cout << '8';
            }
            cout << "\n";
        }
        if (n % 7 == 6){
            cout << 68;
            for (int i=1;i<=(n/7)-1;i++){
                cout << '8';
            }
            cout << "\n";
        }
    }
}
