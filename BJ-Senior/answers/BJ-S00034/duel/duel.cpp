#include <bits/stdc++.h>
using namespace std;
int a[100005],t[100005];
bool cmp(int temp1,int temp2)
{
    return temp1>temp2;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    memset(t,0,sizeof(t));
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int tsum=1;
    t[tsum]=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1])
        {
            t[tsum]++;
        }
        else
        {
            tsum++;
            t[tsum]++;
        }
    }

    int sum=0;
    /*
    for(int i=1;i<=n;i++)
    {
        if(a[i]==-1)
        {
            continue;
        }
        else{
            sum++;
        }
        for(int j=n;j>=i+1;j--)
        {
            if((a[j]<a[i])&&(a[j]!=-1))
            {
                a[j]=-1;
                break;
            }
        }
    }
    */
    for(int i=1;i<=tsum;i++)
    {
        sum=max(sum,t[i]);
    }
    cout<<sum;
    return 0;
}
