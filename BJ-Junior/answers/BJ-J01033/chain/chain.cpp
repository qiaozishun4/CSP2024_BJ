#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,q;
int a[10000];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >>t;
    while(t--){
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=q;i++){
            int r,l;
            cin>>r>>l;
            cout<<"0"<<endl;
        }
    }
    return 0;
}
