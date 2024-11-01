#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n==1)
        {

            cout<<-1;
            cout<<endl;
        }
       else if(n==2)
        {

            cout<<1;
            cout<<endl;
        }
        else if(n==3)
        {

            cout<<7;
            cout<<endl;
        }
        else  if(n==4)
        {
            cout<<4;
            cout<<endl;
        }
        else if(n==5)
        {

            cout<<2;
            cout<<endl;
        }
        else  if(n==6)
        {
            cout<<6;
            cout<<endl;
        }
        else if(n==10)
        {
            cout<<22;
            cout<<endl;
        }
        else if(n%7==0)
        {

            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
        }
        else if(n%7==1)
        {
            cout<<10;
            for(int i=1;i<=(n-8)/7;i++)cout<<8;
            cout<<endl;
        }
        else if(n%7==2)
        {
            cout<<18;
            for(int i=1;i<=(n-9)/7;i++)cout<<8;
        }
        else if(n%7==3)
        {
            cout<<200;
            for(int i=1;i<=(n-17)/7;i++)cout<<8;
            cout<<endl;
        }
        else if(n%7==4)
        {
            cout<<20;
            for(int i=1;i<=(n-11)/7;i++)cout<<8;
            cout<<endl;
        }
        else if(n%7==5)
        {
            cout<<28;
            for(int i=1;i<=(n-12)/7;i++)cout<<8;
            cout<<endl;
        }
        else if(n%7==6)
        {
            cout<<68;
            for(int i=1;i<=(n-13)/7;i++)cout<<8;
            cout<<endl;
        }
    }
    return 0;
}
