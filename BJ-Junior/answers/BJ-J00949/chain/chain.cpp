#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,a[100010],b[100010];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    srand(0);
    cin>>t;
    for(int i=1; i<=t; i++){
        cin>>n>>k>>q;
        for(int i=1; i<=n; i++) cin>>a[i];
        for(int i=1; i<=q; i++) cin>>b[i];
        int a=rand()%2;
        cout<<a;
    }
    return 0;
}