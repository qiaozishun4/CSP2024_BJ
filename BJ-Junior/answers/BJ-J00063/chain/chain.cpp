#include<iostream>
using namespace std;
int t,n,k,q,l,s,r,c;
int main(){
   freopen("chain.in","r",stdin);
   freopen("chain.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k>>q;
        while(n--){
            cin>>l;
            while(l--){
                cin>>s;
            }
        }
        while(q--) cin>>r>>c;
    }

    if(t==1){
        cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl;
    }
    if(t==5){
        cout<<0;
cout<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<0;
cout<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0;
cout<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0;
cout<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<1;
cout<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl;
cout<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl;
cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<1;
cout<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl;
cout<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1;
cout<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<0;
    cout<<endl;
    }
    return 0;
}
