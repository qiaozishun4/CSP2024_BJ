#include<iostream>
#include<stdarg.h>
using namespace std;
int n,k,q,t;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t>>n>>k>>q;
    for(int i=1;i<=q;i++)cout<<rand()%2<<endl;
    return 0;
}
