#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
bool flag[N] = {0};
int t,n,k,q,l,a[N],r,c;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> t;
    while (t--){
        cin >> n >> k >> q;
        memset(flag,0,sizeof(flag));
        while (n--){
            cin >> l;
            for (int i = 1;i <= l;i++) cin >> a[i];
            for (int i = 1;i <= l;i++)
                if (a[i] == 1){
                    for (int j = i + 1;j < i + k;j++)
                        flag[a[j]] = 1;
                }
        }
        while (q--){
            cin >> r >> c;
            cout << flag[c] << endl;
        }
    }
    return 0;
}