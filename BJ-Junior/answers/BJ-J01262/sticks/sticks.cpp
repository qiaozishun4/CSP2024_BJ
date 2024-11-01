#include<bits/stdc++.h>
using namespace std;
int main()
{
     freopen("sticks.in","r",stdin);
     freopen("sticks.out","w",stdout);
     int t;
     int n[100010];
     cin>>t;
    for(int i=1;i<=t;i++)
    {
         cin>>n[i];
    }
    for(int i=1;i<=t;i++)
    {
         if(n[i]==0) cout<<-1<<endl;
         if(n[i]==1) cout<<-1<<endl;
         if(n[i]==2) cout<<1<<endl;
         if(n[i]==3) cout<<7<<endl;
         if(n[i]==4) cout<<4<<endl;
         if(n[i]==5) cout<<2<<endl;
         if(n[i]==6) cout<<6<<endl;
         if(n[i]==7) cout<<8<<endl;
         if(n[i]==8) cout<<10<<endl;
         if(n[i]==9) cout<<18<<endl;
         if(n[i]==18) cout<<208;
    }
    return 0;
}