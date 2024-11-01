#include<bits/stdc++.h>
using namespace std;
long long fgs[20]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long pw(long long a, long long b)
{
    long long ans=1;
    for(long long i=1;i<=b;i++)
        ans*=a;
    return ans;
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, xmin=INT_MAX;
        cin>>n;
        long long sum=0;
        if(n==1)
            sum=0;
        else if(n==2)
            sum=1;
        else if(n==3)
            sum=7;
        else if(n==4)
            sum=11;
        else if(n==5)
            sum=71;
        else
        {
            for(long long i=1;i<=n/3;i++)
            {
                sum+=7*pw(10, i-1);
            }
        }
        for(long long i=1;i<=sum;i++)
        {
            long long cnt=0, ans=0, ai=i;
            while(ai)
            {
                ai/=10;
                cnt++;
            }
            //cout<<cnt<<endl;
            for(long long j=1;j<=cnt;j++)
            {
                ans+=fgs[i%pw(10, j)/pw(10, j-1)];
            }
            //cout<<ans<<endl;
            if(ans!=n)
                continue;
            xmin=min(xmin, i);
        }
        if(xmin==INT_MAX)
            cout<<-1<<endl;
        else
            cout<<xmin<<endl;
    }
    return 0;
}
