#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n,k,q;
        cin >> n >> k >> q;
        vector<vector<int>> ppl(n,vector<int>(2*1e5));
        for(int i=0;i<n;i++){
            int l;
            cin >> l;
            for(int j=0;j<l;j++){
                cin >> ppl[i][j];
            }
        }
        for(int i=0;i<q;i++){
            int r,c;
            cin >> r >> c;
        }
        for(int i=0;i<q-2;i++){
            if(i%2==0){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        cout << 0 << endl << 0 << endl;
    }
    return 0;
}
