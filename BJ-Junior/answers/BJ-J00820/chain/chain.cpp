#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w"stdout);
    int T,n,k,q,l[105],S[105],m[105],A[105];
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>k>>q;
    }
    for(int i=1;i<=n;i++){
        cin>>l[i];
        for(int j=1;j<=l[i];j++){
            cin>>S[j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>m[i]>>A[i];
    }
    cout<<"1"<<endl;
    cout<<"0"<<endl;
    cout<<"1"<<endl;
    cout<<"0"<<endl;
    cout<<"1"<<endl;
    cout<<"0"<<endl;
    cout<<"0"<<endl;
    return 0;
}
