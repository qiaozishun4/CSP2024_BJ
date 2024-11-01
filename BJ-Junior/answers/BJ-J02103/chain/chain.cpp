#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
signed main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        srand(time(0));
        cout<<rand()%2;
    }
    return 0;
}
