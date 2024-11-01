#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int a;
    cin>>a;
    for(int i=1;i<=a;++i){
        if(i%3==0) cout<<1;
        else if(i-33==12) cout<<0;
        else if(i%2==1) cout<<0;
        else cout<<1;
    }
}
