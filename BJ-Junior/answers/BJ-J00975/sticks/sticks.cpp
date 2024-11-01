#include <bits/stdc++.h>
using namespace std;
void ca(int a)
{
    for(int i=1;i<=a;i++)
    {
        cout<<8;
    }
}
void ca2(int a)
{
    cout<<10;
    for(int i=1;i<=a-1;i++)
    {
        cout<<8;
    }
}
void ca3(int a)
{
    cout<<1;
    for(int i=1;i<=a;i++)
    {
        cout<<8;
    }
}
void ca4(int a)
{
    if(a==1)
    {
        cout<<22;
    }
    else
    {
        cout<<200;
        for(int i=1;i<=a-2;i++)
        {
            cout<<8;
        }
    }

}
void ca5(int a)
{
    cout<<20;
    for(int i=1;i<=a-1;i++)
    {
        cout<<8;
    }
}
void ca6(int a)
{
    cout<<2;
    for(int i=1;i<=a;i++)
    {
        cout<<8;
    }
}
void ca7(int a)
{
    cout<<6;
    for(int i=1;i<=a;i++)
    {
        cout<<8;
    }
}
int least(long long p)
{
    if(p==1)
    {
        return -1;
    }
    else if(p==2)
    {
        return 1;
    }
    else if(p==3)
    {
        return 7;
    }
    else if(p==4)
    {
        return 4;
    }
    else if(p==5)
    {
        return 2;
    }
    else if(p==6)
    {
        return 6;
    }
    else if(p==7)
    {
        return 8;
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long t,n;
    cin>>t;
    for(long long i=0;i<t;i++)
    {
        cin>>n;
        if(n<7)
        {
            cout<<least(n)<<endl;
        }
        else if(n%7==0)
        {
            ca(n/7);
            cout<<endl;
            continue;
        }
        else if(n%7==1)
        {
            ca2(n/7);
            cout<<endl;
            continue;
        }
        else if(n%7==2)
        {
            ca3(n/7);
            cout<<endl;
            continue;
        }
        else if(n%7==3)
        {
            ca4(n/7);
            cout<<endl;
            continue;
        }
        else if(n%7==4)
        {
            ca5(n/7);
            cout<<endl;
            continue;
        }
        else if(n%7==5)
        {
            ca6(n/7);
            cout<<endl;
            continue;
        }
        else if(n%7==6)
        {
            ca7(n/7);
            cout<<endl;
            continue;
        }
    }
    return 0;
}
