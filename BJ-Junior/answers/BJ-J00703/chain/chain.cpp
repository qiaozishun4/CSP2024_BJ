#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            cout<<1<<'\n';
        }else{
            cout<<"0"<<'\n';
        }
    }
    return 0;
}
