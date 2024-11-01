#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int> g[N];
void solve(){
    int n,k,q;
    cin >>n>>k>>q;
    for(int i=1;i<=n;i++){
        g[i].clear();
        int len;
        cin >>len;
        for(int j=1;j<=len;j++){
            int x;
            cin >>x;
            g[i].push_back(x);
        }
    }
    while(q--){
        int r,c;
        bool flag=false;
        cin >>r>>c;
        for(int i=1;i<=n;i++){
            for(int j=0;j<g[i].size();j++){
                if(g[i][j]==c){
                    int pos=j;
                    for(int kk=1;kk<=k && pos>=0;kk++){
                        if(g[i][pos]==1){
                            cout <<"1\n";
                            flag=true;
                            break;
                        }
                        pos--;
                    }
                }
                if(flag){
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            continue;
        }
        cout <<"0\n";
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}
