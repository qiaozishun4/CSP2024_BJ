#include <iostream>
using namespace std;

const int num_of_sticks[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
    if(freopen("sticks.in", "r", stdin) == NULL) return 1;
    if(freopen("sticks.out", "w", stdout) == NULL) return 1;

    int T; cin >> T;
    while(T--){
        int n; cin >> n;

        if(n % 7 == 0){
            for(int i = 1; i <= n / 7; i++) cout << "8";
            cout << endl;
            continue;
        }
        else if(n % 7 == 1){
            cout << "10";
            for(int i = 1; i <= n / 7 - 1; i++) cout << "8";
            cout << endl;
            continue;
        }
        else{
            bool flag = 0;
            if((n - 2) % num_of_sticks[0] == 0){
                cout << "1";
                for(int i = 1; i <= (n - 2) / num_of_sticks[0]; i++) cout << "0";
                flag = 1;
            }
            else{
                for(int i = 0; i < 10; i++){
                    if(num_of_sticks[i] == (n - 2) % num_of_sticks[0]){
                        cout << "1";
                        for(int i = 1; i <= (n - 2) / num_of_sticks[0]; i++) cout << "0";
                        cout << i;
                        flag = 1;
                        break;
                    }
                }
            }
            if(!flag) cout << -1;
            cout << endl;
        }
    }
    return 0;
}
