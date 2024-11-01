#include<iostream>
#include<cstdio>
using namespace std;
void sticks(int n)
{

    int s[10];
    for(int i=0;i<=9;i++)s[i]=0;
    if(n==0||n==1)
    {
        cout<<-1<<endl;
        return;
    }
    if(n==6)
    {
        cout<<6<<endl;
        return;
    }
    if(n==5)
    {
        cout<<3<<endl;
        return;
    }
    if(n==4)
    {
        cout<<4<<endl;
        return;
    }
    if(n==2)
    {
        cout<<1<<endl;
        return;
    }
    if(n==3)
    {
        cout<<7<<endl;
        return;
    }
    if(n%7==1)
    {
        int k=n/7;
        cout<<10;
        for(int i=1;i<k;i++)
            cout<<8;
        cout<<endl;
        return;
    }
    if(n%7==2)
    {
        int k=n/7;
        cout<<24;
        for(int i=1;i<k;i++)
            cout<<8;
        cout<<endl;
        return;
    }
    if(n%7==3)
    {
        int k=n/7;
        cout<<22;
        for(int i=1;i<k;i++)
            cout<<8;
        cout<<endl;
        return;
    }
    if(n%7==4)
    {
        int k=n/7;
        cout<<20;
        for(int i=1;i<k;i++)
            cout<<8;
        return;
    }
    if(n%7==5)
    {
        int k=n/7;
        cout<<20;
        for(int i=1;i<k;i++)
            cout<<8;
        return;
    }
    if(n%7==6)
    {
        int k=n/7;
        cout<<6;
        for(int i=1;i<k;i++)
            cout<<8;
        return;
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","r",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int a;
        cin>>a;
        sticks(a);
    }
    return 0;
}