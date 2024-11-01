#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int Q = 1e5 + 5;
const int L = 2e5 + 5;
const int R = 1e2 + 5;
int T;
int n, k, q;
int l[N];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        bool flag[L];
        for(int i = 1; i <= n; i++){
            cin>>l[i];
            int pre = 0;
            int x;
            for(int j = 1; j <= l[i]; j++){
                cin>>x;
                pre--;
                if(pre > 0) flag[x] = 1;
                if(x == 1) pre  = k;
            }
        }
        for(int i = 1; i <= q; i++){
            int r, c;
            cin>>r>>c;
            if(flag[c] == 1) cout<<1<<endl;
            else cout<<0<<endl;

        }
    }
    return 0;
}
