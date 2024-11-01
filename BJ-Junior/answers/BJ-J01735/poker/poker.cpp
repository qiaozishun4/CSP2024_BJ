#include <bits/stdc++.h>
using namespace std;
const long long allpoker = 52;
long long n;
bool vis[256][256];
char hs[] = {'0', 'D', 'C', 'H', 'S'};
char dianshu[] = {'0', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (long long i = 1; i <= n; i++){
        char h_, d_;
        cin >> h_ >> d_;
        vis[h_][d_] = 1;
    }
    long long ans = 0;
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= 13; j++){
            if (vis[hs[i]][dianshu[j]] == 1)
                ans++;
        }
    }
    cout << max(0ll, allpoker - ans);
    return 0;
}
