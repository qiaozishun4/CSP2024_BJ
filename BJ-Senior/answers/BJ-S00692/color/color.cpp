#include<bits/stdc++.h>
using namespace std;
int T,n,a[1000005],c[1000005]={};
bool b[1000005];
long long ans=0;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        ans=0;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
        }
        sort(a+1,a+n+1);
        for(int j=1;j<=n;j++)
        {
            if(a[j]==a[j+1])
            {
                ans+=a[j];
                c[a[j]]=1;
                j++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
