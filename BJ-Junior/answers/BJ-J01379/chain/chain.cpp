#include <bits/stdc++.h>
using namespace std;
int n, k, q;
int s[100010];
int main(){
    //freopen("chain.in", "r", stdin);
    //freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while (T--){
        cin >> n >> k >> q;
        int l;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            for (int j = l; j <= l+x; j++){
                cin >> s[i];
            }
            l+=x;
        }
        for (int i = 1; i <= q; i++){
            int r, c;
            cin >> r >> c;
            if (r == 1){
                for (int j = 1; j <= l; j++){
                    int xx = 1;
                    if (s[l] == 1){
                        xx = s[l];
                        for (int j = xx; j <= xx+q; j++)
                    }
                }
            }
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
