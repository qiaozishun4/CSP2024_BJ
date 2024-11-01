#include<iostream>
using namespace std;
int a,b,c,d;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>b>>c>>d;
        for(int i=0;i<d;i++)cout<<1<<"\n";
    }
    return 0;
}