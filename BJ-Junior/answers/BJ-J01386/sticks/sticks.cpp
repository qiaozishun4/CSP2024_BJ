#include<bits/stdc++.h>
using namespace std;

long long a[105] = {-1, 1, 7, 4, 2, 6, 8};

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    for(int i=8; i<=20; i++){
        long long mn=0x3f3f3f3f;
        for(int j=2; j<i; j++){
            mn = min(mn, (a[j]*10 + a[i-j]));
        }
        a[i] = mn;
    }

    long long t; cin >> t;
    while(t--){
        long long n; cin >> n;
        cout << a[n] << '\n';
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
