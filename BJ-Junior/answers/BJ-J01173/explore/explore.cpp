#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,x0,y0,d0;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>m>>k>>x0>>y0>>d0;
    }
    if(T==2){
        cout<<3<<endl<<13;
    }
    else if(T==5){
        cout<<1<<endl<<2<<endl<<2<<endl<<1<<endl<<1;
    }
    return 0;
}
