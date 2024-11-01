#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans,last1,last2=1,b[100005],t=1;
bool check(int x)
{
    int last=2,num=0,ret=0,sum=0;
    for(int i=1; i<=t-1; i++)
    {
        int die=0;
        for(int j=last; j<=t; j++)
        {
            if(die+b[j]>=b[i])
            {
                if(last==i+1)
                {
                    die=b[i];
                    last=j+1;
                    num=0;
                    break;
                }
                else
                {
                    last=j+1;
                    num=die+b[j]-b[i];
                    die=b[i];
                    break;
                }
            }

            if(j==t)
            {
                ret++;
            }
            die=die+b[j];
        }
        if(ret==1)
        {

            break;
        }
        sum=sum+die;
    }
    if(sum>=n-x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    last1=a[1];
    for(int i=1; i<=n; i++)
    {
        if(last1!=a[i])
        {
            last1=a[i];
            b[t]=i-last2;
            t++;
            last2=i;
        }
    }
    b[t]=n-last2+1;
    if(t==1)
    {
        cout<<n;
        return 0;
    }
    if(t==2)
    {
        cout<<n-min(b[1],b[2]);
        return 0;
    }
    int left=1,right=n;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(check(mid))
        {
            ans=mid;
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    cout<<ans-1;
    return 0;
}
