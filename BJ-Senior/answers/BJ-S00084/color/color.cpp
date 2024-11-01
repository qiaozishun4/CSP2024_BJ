#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        int n;
        cin>>n;
        int a[200005]={};
        int big=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]>big)
            {
                big=a[i];
            }
        }
        int cases[1000005]={};
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cases[a[i]]++;
        }
        for(int i=1;i<=big;i++)
        {
            ans+=cases[i]/2*i;
        }
        cout<<ans<<endl;
    }
}
