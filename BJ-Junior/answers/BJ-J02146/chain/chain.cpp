#include <bits/stdc++.h>
using namespace std;

vector<int> v[1010];

int main(){
    freopen("chain2.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n, k, q;
        for(int i = 1;i <= n;i++){
            int l;
            cin >> l;
            for(int j = 1;j <= l;j++){
                int p;
                cin >> p;
                v[i].push_back(p);
            }
        }
        for(int i = 1;i <= q;i++){
            int r, c, ans = 0;
            cin >> r >> c;
            for(int j = 1;j <= n;j++){
                for(int l = 1;l < v[j].size()-k+1;l++){
                    for(int o = 1;o < k;o++){
                        if(v[j][l+o]==c)ans = 1;
                    }
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
