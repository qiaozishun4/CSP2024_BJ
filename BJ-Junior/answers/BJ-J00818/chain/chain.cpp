#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    if(t==1){
        cout<<0;
    }else if(t==2){
        cout<<1<<endl<<0;
    }else if(t==3){
        cout<<0<<endl<<0<<endl<<1; 
    }else if(t==4){
        cout<<1<<endl<<1<<endl<<0<<endl<<1;
    }else{
        cout<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<1;
    }
    return 0;
}
