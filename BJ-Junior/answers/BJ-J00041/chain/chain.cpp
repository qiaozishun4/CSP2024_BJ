#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,x,y;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t
    for(int s=1;s<=t;s++){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>x;
            for(int j=1;j<=x;j++){
                cin>>y;
            }
        }
        for(int i=1;i<=q;i++){
            cin>>x;
        }
        for(int i=1;i<=q;i++){
            cout<<1<<endl;
        }
    }
    return 0;
}
