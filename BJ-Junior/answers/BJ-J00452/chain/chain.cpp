#include<bits/stdc++.h>
using namespace std;
signed main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    srand(time(0)^(unsigned long long) new char);
    cin>>t;
    while(t--){
        cout<<rand()%2<<endl;
    }
    return 0;
}
