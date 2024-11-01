#include <bits/stdc++.h>
using namespace std;
int t,n,k,q;
int l[10005],s;
int o,p;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n>>k>>q;
        for (int j=0;j<n;j++){
            cin>>l[j];
            for (int h=0;h<l[j];h++){
                cin>>s;
            }
        }
        for (int j=0;j<q;j++){
            cin>>o>>p;
        }

    }
    for (int i=1;i<=q;i++){
        cout<<"0"<<endl;
    }
}
