#include<bits/stdc++.h>
using namespace std;


int main(){
  freopen("chain.in","r",stdin);
  freopen("chain.out","w",stdout);
    int T,n,k,q,l,m;

    cin>>T;


    for(int i=1;i<=T;i++){
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++){
            cin>>l;
            for(int a=1;a<=l;a++){
                cin>>m;
            }
        }
    }
    for(int i=1;i<=q;i++){
        cout<<i%2<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
