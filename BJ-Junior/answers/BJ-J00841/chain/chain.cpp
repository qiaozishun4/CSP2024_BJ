#include <bits/stdc++.h>
using namespace std;
long long t;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    cin>>t;
    for(int i=1;i<=t;++i){
        long long n,k,q,s=1;
        cin>>n>>k>>q;
        for(int j=1;j<=q;j++){
            if(s==1){
                cout<<"1"<<endl;
                s=0;
            }else if(s==0){
                cout<<"0"<<endl;
                s=1;
            }


        }


    }
    return 0;
}
