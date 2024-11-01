#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 20000007, k[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

long long mem[N];

long long cal(long long x){
    int a = x;

    int n = 0;
    if(mem[x]) return mem[x];
    while(x > 0){
        n += k[x % 10];
        x /= 10;
    }
    mem[a] = n;

    return n;
}

long long solve(long long n){
    for(int i = 1;;i++){
        if(!mem[i]) cal(i);
        if(mem[i] == n) return i;
    }
    return -1;
}

int n;
string s, ans = "-1";

signed main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    int q;
    cin >> q;
    while(q--){
        cin >> n;
        if(n <= 1){
            cout << "-1\n";
            continue;
        }
        if(n % 7 == 0){
            for(int i = 1;i <= n;i += 7) cout << "8";
        }
        else if((n-1) % 7 == 0){
            cout << "10";
            n -= 8;
            for(int i = 1;i <= n;i += 7) cout << "8";
        }
        else if(n > 50){
             if(n % 7 == 2){
                cout << "1";
            }
            if(n % 7 == 3){
                cout << "7";
            }
            if(n % 7 == 4){
                cout << "20";
                n -= 7;
            }
            if(n % 7 == 5){
                cout << "2";
            }
            if(n % 7 == 6){
                cout << "6";
            }
            for(int i = 1;i <= n/7;i++){
                cout << "8";
            }
        }
        else{
            cout << solve(n);
        }
        cout << "\n";
    }

    return 0;
}
