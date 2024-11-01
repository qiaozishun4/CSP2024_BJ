#include<bits/stdc++.h>
using namespace std;
int aop[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >>n;
        if(n == 1){
            cout << -1;
            cout <<endl;
            continue;
        }
        int f = 0;
        int op = n / 7;
        int op12 = n / 7 +1;
        long long op1 = 1;
        long long op123 = 1;
        for(int i = 1;i <= op; i++){
            op1 *= 10;
        }
        for(int i = 1;i <= op12; i++){
            op123 *= 10;
        }
        for(long long i = op1; i <= op123; i++){
            long long v = i;
            int sum = 0;
            while(v > 0){
                sum += aop[v % 10];
                v /= 10;
            }
            if(sum == n){
                cout << i;
                f = 1;
                break;
            }
        }
        if(f == 0){
            cout <<-1;
        }
        cout <<endl;
    }
    return 0;
}
