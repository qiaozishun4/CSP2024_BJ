#include <bits/stdc++.h>
using namespace std;
int ans[22]={-1,-1,1,7,4,2,6,8,18,24,22,20,28,68,88,108,188,228,208,288,688,888};
long long biao[100005];
int wei(int n)
{
    int wei;
    if(n%7==0)
    {
        wei=n/7;
    }
    else
    {
        wei=n/7+1;
    }
    return wei;
}
long long f(int n)
{
    if(biao[n]!=0)
    {
        return biao[n];
    }
    if(n<=21)
    {
        return ans[n];
    }
    long long x1=f(n-2)+1*wei(n-2);
    long long x2=f(n-5)+5*wei(n-5);
    long long x3=f(n-6)+6*wei(n-6);
    long long x4=f(n-7)+7*wei(n-7);
    return biao[n]=min(min(x1,x2),min(x3,x4));
}
int main()
{
    int t;
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    while(t--)
    {
        int n;
        cin>>n;
        if(n<=21)
        {
            cout<<ans[n]<<endl;
            continue;
        }
        cout<<f(n)<<endl;
    }
}
