#include <iostream>

using namespace std;
int dnum[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int f[50010];
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    for(int i = 1; i <= 50000; i++){
        if(i <= 9){
            f[i] = dnum[i];
        } else if(i >= 10 && i <= 99){
            f[i] = dnum[i % 10] + dnum[i / 10];
        } else if(i >= 100 && i <= 999){
            f[i] = dnum[i % 10] + dnum[i / 100] + dnum[i / 10 % 10];
        } else if(i >= 1000 && i <= 9999){
            f[i] = dnum[i % 10] + dnum[i / 1000] + dnum[i / 10 % 10] + dnum[i / 100 % 10];
        } else{
            f[i] = dnum[i % 10] + dnum[i / 10000] + dnum[i / 10 % 10] + dnum[i / 100 % 10] + dnum[i / 1000 % 10];
        }
    }
    //for(int i = 1; i <= 10000; i++) cout << i << " " << f[i] << "\n";
    int t; cin >> t;
    while(t--){
        bool flag = false;
        int n; cin >> n;
        if(n < 2){
            cout << "-1\n";
            continue;
        }
        for(int i = 1; i <= 50000; i++){
            if(f[i] == n){
                cout << i << "\n";
                flag = true;
                break;
            }
        }
        if(!flag) cout << "-1\n";
    }
    return 0;
}
