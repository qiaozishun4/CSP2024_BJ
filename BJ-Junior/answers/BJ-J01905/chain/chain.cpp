#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        if(i%2==1)cout<<"1\n";
        else cout<<"0\n";
    }
    return 0;
}
