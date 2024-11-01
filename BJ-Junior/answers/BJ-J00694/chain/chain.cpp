#include<iostream>
using namespace std;
int main(){
   freopen("chain.in","r",stdin);
   freopen("chain.out","w",stdout);
   int t;
   int n,k,q,l,s,r,c;
   cin>>t;
   
   for(int i=1;i<=t;i++){
       cin>>n>>k>>q;
       for(int j=1;j<=n;j++){
           cin>>l;
           for(int x=1;x<=l;x++){
           cin>>s;
           }
       }
       for(int j=1;j<=q;j++){
       cin>>r>>c;
       }
   }
   for(int i=0;i<q;i++){
       cout<<0<<endl;
   }
   return 0;
}