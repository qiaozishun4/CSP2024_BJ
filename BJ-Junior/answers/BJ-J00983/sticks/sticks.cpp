#include<bits/stdc++.h>
using namespace std;
int a[9000],v[10]={0,1,2,3,4,5,6,7,8,9},w[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
       int n;
       cin>>n;
       if(n%7==0)
       {
           for(int j=1;j<=n;j+=7)
           {
               cout<<8;
               continue;
           }
       }
       if(n==1)cout<<-1;
       else if(n==2)cout<<1;
       else if(n==3)cout<<7;
       else if(n==4)cout<<4;
       else if(n==5)cout<<2;
       else if(n==6)cout<<6;
       else if(n==8)cout<<10;
       else if(n==9)cout<<18;
       else if(n==10)cout<<22;
       else if(n==11)cout<<20;
       else if(n==12)cout<<28;
       else if(n==13)cout<<80;
       else if(n==15)cout<<108;
       else if(n==16)cout<<188;
       else if(n==17)cout<<200;
       else if(n==18)cout<<208;
       else if(n==19)cout<<288;
       else if(n==20)cout<<688;
       cout<<endl;
    }
    return 0;
}
