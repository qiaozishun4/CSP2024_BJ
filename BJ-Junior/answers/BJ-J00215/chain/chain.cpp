#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 2e5 + 10;
bool have[N];
int r[N] , c[N];
vector<int>l[N] , mx[N];
int n , k , q;
int solve1(int x){
    for (int i = 1; i <= n; i++){
        mx[i].push_back(-1e9);
        for (int j = 1; j <= l[i][0]; j++){
            mx[i].push_back(mx[i][j-1]);
            if (l[i][j] == 1)mx[i][j] = j;
        }
        int lst = -1;
        for (int j = 1; j <= l[i][0]; j++)
            if (l[i][j] == c[x]){
                if (c[x] == 1 && lst != -1 && (j - lst + 1) <= k)return 1;
                if (c[x] != 1 && mx[i][j] != -1e9 && (j - mx[i][j] + 1) <= k)return 1;
                lst = j;
            }
    }
    return 0;
}
int main(){
    freopen("chain.in" , "r" , stdin);
    freopen("chain.out" , "w" , stdout);
    int T;
    cin >> T;
    while (T--){
        cin >> n >> k >> q;
        memset(have , false , sizeof(have));
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            l[i].push_back(x);
            for (int j = 1; j <= l[i][0]; j++){
                int x;
                cin >> x;
                l[i].push_back(x);
                have[x] = true;
            }
        }
        if (have[1] == false){
            while (q--)cout << "0\n";
            continue;
        }
        for (int i = 1; i <= q; i++)cin >> r[i] >> c[i];
        for (int i = 1; i <= q; i++){
            if (r[i] == 1)cout << solve1(i) << '\n';
        }
    }
    return 0;
}