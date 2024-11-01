#include<bits/stdc++.h>
using namespace std;
const int d[]={6,2,5,5,4,5,6,3,7,6};
long long chk(long long x)
{
    int ans=x;
    int sum=0;
    while(ans)
    {
        sum+=d[ans%10];
        ans/=10;
    }
    return sum;
}
long long sol(long long x)
{
    long long ans=x/2;
    if(x%2==1)x++;
    long long sum=0;
    while(x--)sum=sum*10+9;
    return sum;
}
long long read()
{
    long long x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-48;
        ch=getchar();
    }
    return x;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long t=read();
    while(t--)
    {
        long long n=read();
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        else
        {
            long long ans=1;
            while(ans<=sol(n))
            {
                if(chk(ans)==n)break;
                ans++;
            }
            if(chk(ans)==n)cout<<ans;
            else cout<<-1;
            cout<<endl;
        }
    }
    return 0;
}
