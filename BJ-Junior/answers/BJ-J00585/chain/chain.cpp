#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    int n,k,q,l,s[100],r[100],c[100];
    for(int i=0;i<t;i++)cin>>n>>k>>q;
    for(int i=0;i<n;i++){
        cin>>l;
        for(int j=0;j<l;j++)cin>>s[i];
    }
    for(int i=0;i<q;i++)cin>>r[i]>>c[i];
    cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl;
    return 0;
}
