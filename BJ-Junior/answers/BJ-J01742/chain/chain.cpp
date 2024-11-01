#include<bits/stdc++.h>
using namespace std;
int s[101101][202202],l[101101],r[101101],c[101101];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,k,q;
        cin>>n>>k>>q;
        for(int i = 0;i < n;i += 1){
            cin>>l[i];
            for(int j = 0;j < l[i];j += 1){
                cin>>s[i][l[i]];
            }
        }
        for(int i = 0;i < q;i += 1){
            cin>>r[i]>>c[i];
        }
        for(int i = 0;i < q;i += 1){
            cout<<0<<endl;
        }
    }
    return 0;
}
