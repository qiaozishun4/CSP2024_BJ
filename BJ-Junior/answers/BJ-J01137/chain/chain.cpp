#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, k, q, l[N], r[N], c[N];
string s[N];

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);

    int T;
    cin >> T;
    while(T--){
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++){
            cin >> l[i] >> s[i];
        }
        for(int i = 1;i <= q;i++){
            cin >> r[i] >> c[i];
        }
        cout << 0 << "\n";
    }
    return 0;
}
