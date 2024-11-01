#include<bits/stdc++.h>
using namespace std;

int a[100005]={};

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int l=100005,r=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<l)
        {
            l=a[i];
        }
        if(a[i]>r)
        {
            r=a[i];
        }
    }
    int ans=n,t=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        int small=0,big=0;
        bool tb=true;
        int flag=-1;
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<=mid)
            {
                small++;
            }
            else
            {
                big++;
                if(flag==-1)
                {
                    flag=a[i];
                }
                if(a[i]!=flag)
                {
                    tb=false;
                }
            }
        }
        if(big==0)
        {
            t=small;
        }
        else if(tb&&big>small)
        {
            t=big;
        }
        else
        {
            t=big+small-big;
        }
        if(t<ans)
        {
            ans=t;
        }
        if(small>big)
        {
            r=mid-1;
        }
        else if(small==big)
        {
            cout<<small;
            return 0;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
