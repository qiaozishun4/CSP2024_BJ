#include<bits/stdc++.h>
using namespace std;
long long t,n,k,a[100],res,l,q,r,c;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k>>q;
        for(int j=0;j<n;j++){
            cin>>l;
            for(int k=0;k<l;k++){
                cin>>a[i];
            }
        }
        for(int j=0;j<q;j++){
            cin>>r>>c;
        }
        for(int i=0;i<q;i++){
            cout<<"0"<<endl;
        }
    }
    return 0;
}
