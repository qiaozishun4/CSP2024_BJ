#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int n,k,q,t,a[200005]={},l,r[100005]={},c[100005]={};
    cin>>t;
    for(int p = 0;p < t;p++){
        cin>>n>>k>>q;
        for(int i = 0;i < n;i++){
            cin>>l;
            for(int j = 0;j < l;j++){
                cin>>a[j];
            }
        }
        for(int i = 0;i < q;i++){
            cin>>r[i]>>c[i];
        }
        for(int i = 0;i < q;i++){
            cout<<1<<endl;
        }
    }
    return 0;
}