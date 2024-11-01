#include<bits/stdc++.h>
using namespace std;
int f[]={6,2,5,5,4,5,6,3,7,6};
int t,n;
const int N=1e8+5;
int dpn[N];
int sum(int i)
{
    int summ=0;
    while(i)
    {
        summ+=f[i%10];
        i/=10;
    }
    return summ;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    dpn[50]=50000888;
    dpn[49]=49000888;
    dpn[48]=48000008;
    dpn[47]=2888888;
    dpn[46]=2088888;
    dpn[45]=2008888;
    dpn[44]=1888888;
    dpn[43]=1088888;
    while(t--)
    {
        bool f=0;
        cin>>n;
        if(dpn[n])
        {
            cout<<dpn[n]<<"\n";
            continue;
        }
        if(n==1)
        {
            cout<<-1<<"\n";
            continue;
        }
        if(n<=20)
        {
            for(int i=1;i<=n*5000;i++)
            {
                int x=0;
                x=sum(i);
                if(x==n)
                {
                    f=1;
                    dpn[n]=min(dpn[n],i);
                    cout<<i<<"\n";
                    break;
                }

            }
            if(f==0)
            {
                cout<<-1<<"\n";
            }
        }
        else
        {
            for(int i=1;i<=n*90000;i++)
            {
                int x=0;
                x=sum(i);
                if(x==n)
                {
                    f=1;
                    dpn[n]=min(dpn[n],i);
                    cout<<i<<"\n";
                    break;
                }

            }
            if(f==0)
            {
                cout<<-1<<"\n";
            }
        }

    }
    return 0;
}
