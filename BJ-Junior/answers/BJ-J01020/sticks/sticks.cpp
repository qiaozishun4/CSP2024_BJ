#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>m;
   for(int i=1;i<=m;i++)
   {
       cin>>n;
       if(n%7==0)
       {
           for(int u=1;u<=(n/7);u++)
           {
               cout<<"8";

           }
           cout<<endl;
       }
       else if(n%7==1){
        for(int u=1;u<=(n/7)-1;u++)
           {
               cout<<"8";

           }
           cout<<"19"
           cout<<endl;
       }
       else{
        cout<<"-1";
       }
   }

}
