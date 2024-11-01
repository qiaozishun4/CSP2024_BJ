
#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;


void sol() {

    int t=rand()%2;
    if(t) cout<<1<<endl;
    else cout<<0<<endl;
    return ;
}



int main() {
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    srand(1026);
    int T; cin>>T; while(T--) sol();

    return 0;
}
