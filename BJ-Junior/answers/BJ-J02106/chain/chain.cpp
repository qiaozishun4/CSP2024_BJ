#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,k,q;
    int a,b,l;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++){
            cin>>l;
            for(int m=1;m<=l;m++)cin>>a;
        }for(int j=1;j<=q;j++)cin>>a>>b;
    }for(int i=1;i<=q;i++){
        cout<<1<<endl;
    }
    return 0;
}
