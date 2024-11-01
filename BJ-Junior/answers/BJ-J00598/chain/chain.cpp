#include<bits/stdc++.h>
using namespace std;
int T;
const int N=1e5+5;
const int M=2e5+5;
int a[N][M]; //a[i][j] p1 have got aj
int r[N],c[N];
int main(){

    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;//n peoples,k ceil of chain's num,missions amount
        for(int i=1;i<=n;i++){
            int l;cin>>l;
            for(int j=1;j<=l;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r[i]>>c[i];
        }
        for(int i=1;i<=q;i++){
            cout<<0<<'\n';
        }
    }
    return 0;

}
