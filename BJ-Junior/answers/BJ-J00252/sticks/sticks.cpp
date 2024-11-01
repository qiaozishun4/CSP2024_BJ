#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       cin>>x;
       if(x<=1)
       {
           cout<<-1<<endl;
           continue;
       }
       if(x==2)
       {
           cout<<1<<endl;
           continue;
       }
       if(x==3)
       {
           cout<<7<<endl;
           continue;
       }
       if(x==4)
       {
           cout<<-1<<endl;
           continue;
       }
       if(x==5)
       {
           cout<<2<<endl;
           continue;
       }
       if(x==6)
       {
           cout<<6<<endl;
           continue;
       }
       if(x==7)
       {
           cout<<8<<endl;
           continue;
       }
    }
    return 0;
}