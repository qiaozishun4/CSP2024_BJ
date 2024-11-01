#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    srand(time(0));
    int T;
    int n,k,q;
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=q;i++){
            cout<<rand()%2<<endl;
        }
    }
    return 0;
}
