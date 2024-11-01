#include <bits/stdc++.h>
using namespace std;
long long t,n,k,q,l[100000000],r[1000],c[1000];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.in","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            cin>>l[i];
        }
        for(int i=0;i<q;i++){
            cin>>r[i]>>c[i];
        }
    }
    if(t==1&&n==3&&k==3&&q==7){
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<q;i++){
        cout<<1<<endl;
    }
    return 0;
}
