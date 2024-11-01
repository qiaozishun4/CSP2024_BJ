#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int a[100010];
bool f[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=1;
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[i]>a[j]&&f[j]==1)
            {
                f[j]=0;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i]==1)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
