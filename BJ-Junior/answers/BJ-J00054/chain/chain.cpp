#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 100005;
constexpr int MAXR = 105;

int T, n, k, q, l;
int S[2005];
int que[2005];
bool reach[200005];
int cnt;

int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        cin >> n >> k >> q;
        while(n--){
            cin >> l;
            for(int i = 1; i <= l; i ++)
                cin >> S[i];
            for(int i = 2; i <= k; i ++){
                    reach[S[i]] = 1;
            }
        }
        while(q--){
            int a, b;
            cin >> a >> b;
            if(reach[b])
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
    return 0;
}
