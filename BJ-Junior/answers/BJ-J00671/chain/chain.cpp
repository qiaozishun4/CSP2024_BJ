#include<bits/stdc++.h>
using namespace std;
int s,a,b,c;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>s;
    cin>>a>>b>>c;
    for(int i=1;i<=c;i++){
        if(i%2)cout<<1;
        else cout<<0;
        cout<<endl;
    }
    return 0;
}
