#include<bits/stdc++.h>
using namespace std;
long long a[100000];
long long s[100000]={0};
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[a[i]]++;
    }
    long long k=1;
    long long sum=0,max=-1,maxn=-1;
    for(int i=1;i<=100000;i++)
    {
        if(max<a[i])
        {
           max=a[i];
       }
       if(s[max]>maxn)
       {
           maxn=max;
       }
   }
    for(long long i=2;i<=100000;i++)
    {
        if(s[i]!=0)
        {
           if(s[i]<s[k])
           {
               sum=s[i]+sum;
               s[k]=s[i]-s[k];
               s[i]=0;
           }
           else if(s[i]>s[k])
           {
               sum=sum+s[k];
               s[i]=s[i]-s[k];
               s[k]=0;
           }
           else
           {
              sum=sum+s[k];
              s[k]=0;
           }
           k=i;
        }
    }
    if(maxn==max)
    {
        cout<<maxn;
    }
    else
    {

    cout<<n-sum;
    }
    return 0;
}