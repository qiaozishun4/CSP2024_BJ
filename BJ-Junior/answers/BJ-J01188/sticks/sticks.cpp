#include <bits/stdc++.h>
using namespace std;
bool q;
long long a[1000000],t,n;
long long shu[10]={6,2,5,5,4,5,6,3,7,6};
long long sum(long long nb)
{
    long long cmp,ans=0;
    while(nb)
    {
        cmp=nb%10;
        ans=ans+shu[cmp];
        nb=nb/10;
    }
    return ans;
}
long long fang(long long n)
{
    long long ans=1;
    while(n)
    {
        ans*=3;
        n--;
    }
    return ans;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    memset(a,0,sizeof(a));
    cin>>t;
    for(long long i=0;i<t;++i)
    {
        q=false;
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n==2)
        {
            cout<<1<<endl;
            continue;
        }
        if(n==3)
        {
            cout<<7<<endl;
           continue;
        }
        if(n==4)
        {
            cout<<4<<endl;
            continue;
        }
        if(n==5)
        {
            cout<<2<<endl;
            continue;
        }
        if(n==6)
        {
            cout<<6<<endl;
            continue;
        }
        if(n==7)
        {
            cout<<8<<endl;
            continue;
        }
        for(long long j=n;j<fang(n/3);++j)
            if(sum(j)==n)
            {
                cout<<j<<endl;
                q=true;
                break;
            }
        if(q==false)cout<<-1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
