#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("color.in","r",stdin);
    feropen("color.out","w",stdout);
    const int n=10010;
    int T,n;
    int a[N],c[N];
    cin>>T;
    int ans,sum;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int j=0;j<=(l<<n)-1;p++)
        {
            for(int i=n;i>=1;i--)
            {
                c[i]=s%2;
                s/=2;
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=i-1;j>=i;j--)
                {
                    if(c[i==c[j]&&a[i]==a[j])
                    {
                        int sum;
                        sum+=a[j];
                    }
                }
            }
        }
    }
    ans=max(max,ans);
    cout<<ans;
    return 0;
}