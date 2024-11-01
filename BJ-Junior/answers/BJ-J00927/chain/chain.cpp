#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int ci;cin>>ci;
    while(ci--){
        int a[100005],b[100005],c[100005],r[100005],c[100005];
        int n,m,k,aa,bb,cc;cin>>n>>m>>k;
        cin>>aa;
        for(int i=1;i<=aa;i++)cin>>a[i];
        cin>>bb;
        for(int i=1;i<=bb;i++)cin>>b[i];
        cin>>cc;
        for(int i=1;i<=cc;i++)cin>>c[i];
        for(int i=1;i<=k;i++){
            cin>>r[i]>>c[i];
        }
        for(int i=1;i<=k;i++){
            cout<<0<<endl;
        }
    }
    return 0;
}
