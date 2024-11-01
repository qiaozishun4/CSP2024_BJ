#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("sticks.in","r",stdin);
   freopen("sticks.out","w",stdout);
   int t;
   cin>>t;
   for(int i=0;i<t;i++){
   int n;
   cin>>n;
   if(n==1) cout<<'-'<<1;
   else  {
   if(n==2) cout<<1<<" ";
   if(n==3) cout<<7<<" ";
   if(n==4) cout<<4<<" ";
   if(n==5) cout<<2<<" ";
   if(n==6) cout<<6<<" ";
   if(n==7) cout<<8<<" ";
   if(n==8) cout<<10<<" ";
   if(n==9) cout<<18<<" ";
   if(n==10) cout<<22<<" ";
   if(n==11) cout<<20<<" ";
   if(n==12) cout<<28<<" ";
   if(n==13) cout<<68<<" ";
   if(n==14) cout<<88<<" ";
   if(n%7==0){
      for(int j=1;j<=n/7;j++)
      {
         cout<<8;
      }
      cout<<" ";
   }
   if(n%7==1){
      cout<<1;
      for(int j=1;j<=(n-1)/7;j++)
      {
        cout<<8;
      }
      cout<<" ";
   }


   }

   }
   return 0;
}
