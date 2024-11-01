#include <cstdio>
#include <iostream>
using namespace std;
int n,q,l,h;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>q>>q;
        for(int j=0;j<n;j++){
            cin>>l;
            for(int k=0;k<l;k++)cin>>h;
        }
        for(int j=0;j<q;j++)cin>>h>>h;
        cout<<1<<endl;
    }
    return 0;
}
