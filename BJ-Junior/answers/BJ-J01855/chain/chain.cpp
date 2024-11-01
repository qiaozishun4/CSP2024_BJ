#include<bits/stdc++.h>
using namespace std;
long long t, n, k, q, a, l, z[100000010], o, r, c;
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin>>t;
    for(int i = 1; i <= t; i++){
        cin>>n>>k>>q;
        for(int j = 1; j <= n; j++){
            cin>>l;
            for(int k1 = 1; k1 <= l; k1++){
                cin>>a;
                if(a == 1){
                    o = k1;
                }
                if(o != 0){
                    if(z[a] == 0){
                        z[a] = k1 - o + 1;
                    }else{
                        z[a] = min(z[a], k1 - o + 1);
                    }
                }
            }
            o = 0;
        }
        for(int j = 1; j <= q; j++){
            cin>>r>>c;
            if(r == 0){
                cout<<"0"<<endl;
                break;
            }
            if(z[c] <= k&&z[c] != 0){
                cout<<"1"<<endl;
            }else{
                cout<<"0"<<endl;
            }
        }
        for(int j = 1; j <= 100010; j++){
            z[j] = 0;
        }
    }
    return 0;
}
