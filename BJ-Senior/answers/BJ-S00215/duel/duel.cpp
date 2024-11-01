#include<bits/stdc++.h>
using namespace std;
long  long x[1000010],y[1000010],z=0,sum;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n;
    cin>>n;
    sum=n;
    for(long long i=1;i<=n;i++)
    {
        long long a;
        cin>>a;
        x[a]++;
    }
    for(long long i=1;i<=1000000;i++)
    {
        if(x[i]!=0)
        {
            y[++z]=x[i];
        }
    }
    for(long long i=2;i<=z;i++)
    {
        sum-=min(y[i],y[i-1]);
        if(y[i]>=y[i-1]) y[i-1]=0;
        else y[i-1]=y[i-1]-y[i];
        if(y[i-1]>=0)
        {
            y[i]+=y[i-1];
        }
    }
    cout<<sum;
    return 0;
}
