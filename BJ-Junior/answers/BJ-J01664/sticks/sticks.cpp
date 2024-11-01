#include<bits/stdc++.h>
using namespace std;
long long n,t,x,d,jia,sum,mo,chu;
int b[11]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%lld",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        if(n<2)
        {
            cout<<-1<<endl;
            continue;
        }
        for(long long j=1;j<=100000;j++)
        {
            sum=0;
            d=1;
            if(j>=10)
                d=2;
            if(j>=100)
                d=3;
            if(j>=1000)
                d=4;
            if(j>=10000)
                d=5;
            if(j>=100000)
                d=6;
            for(int p=1;p<=d;p++)
            {
                mo=pow(10,p);
                chu=mo/10;
                jia=(j%mo)/chu;
                jia=b[jia];
                sum+=jia;
            }
            if(sum==n)
            {
                printf("%lld",j);
                cout<<endl;

                break;
            }

        }
    }
    return 0;
}
