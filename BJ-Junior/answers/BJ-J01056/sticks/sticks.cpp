#include <bits/stdc++.h>
using namespace std;
long long t, n;
int a[]={-1, -1, 1, 7, 4, 2, 6, 8, 16, 24, 22, 26, 28, 68, 88, 168, 188, 200, 208, 288, 488};
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    std::cin>>t;
    while(t--)
    {
        std::cin>>n;
        if(n<=20) {cout<<a[n]<<"\n";continue;}
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++) std::cout<<8;
        }
        if((n-1)%7==0)
        {
            std::cout<<16;
            for(int i=1;i<=n/7-1;i++) std::cout<<8;
        }
        if(n%7==2)
        {
            std::cout<<1;
            for(int i=1;i<=n/7;i++) std::cout<<8;
        }
        if(n%7==3)
        {
            std::cout<<22;
            for(int i=1;i<=n/7;i++) std::cout<<8;
        }
        if(n%7==4)
        {
            std::cout<<20;
            for(int i=1;i<=n/7-1;i++) std::cout<<8;
        }
        if(n%7==5)
        {
            std::cout<<2;
            for(int i=1;i<=n/7;i++) std::cout<<8;
        }
        if(n%7==6)
        {
            std::cout<<4;
            for(int i=1;i<=n/7;i++) std::cout<<8;
        }
        std::cout<<"\n";
    }
    return 0;
}
