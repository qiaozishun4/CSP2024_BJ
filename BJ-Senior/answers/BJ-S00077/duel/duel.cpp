#include<bits/stdc++.h>
using namespace std;
int ddd,sum;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    bool panduan = false;
    int n,sum,l=1000000;
    cin>>n;
    int a[10005];
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            ddd=j;
            if(a[i]==-1 || a[j]==-1)
            {
                panduan=true;
                continue;
            }
            if(i==j)
            {
                panduan = true;
                continue;
            }
            if(a[i]-a[j]==1)
            {
                a[j]=-1;
                panduan = true;
                continue;
            }
            else if(a[i]-a[j]<l && a[i]-a[j]>=2)
            {
                l=j;
            }
        }
        if (panduan == true)
        {
            continue;
        }
        else if (l!=1000000)
        {
            a[ddd]=-1;
            continue;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=-1)
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}

