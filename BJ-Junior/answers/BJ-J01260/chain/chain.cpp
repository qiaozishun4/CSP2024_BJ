#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector <int> v[N];
int T,q,n,k,tmp[N];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        memset(tmp,0,sizeof(tmp));
        for(int i=1;i<=n;i++){
            v[i].clear();
        }
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            for(int j=1;j<=l;j++){
                int in;
                cin>>in;
                v[i].push_back(in);
                tmp[in]++;
            }
        }
        while(q--){
            int r,c;
            cin>>r>>c;
            if(tmp[c]) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}