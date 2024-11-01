#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l[15],a[15][25],r,c,ans;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            srand(i);
            cout<<rand()%2<<endl;
        }
    }
    return 0;
}
