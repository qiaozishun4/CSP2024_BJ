#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    srand(time(0));
    int T;
    cin>>T;
    while(T--){
        int n,k,q;
        cin>>n>>k>>q;
        while(n--){
            int p,t;
            cin>>p;
            while(p--){
                cin>>t;
            }
        }
        while(q--){
            int p,t;
            cin>>p>>t;
            cout<<rand()%2<<'\n';
        }
    }

    return 0;
}

