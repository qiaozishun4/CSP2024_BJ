#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int ans=0;
        for(int i=0;i<1<<n;i++)
        {
            int cnt=0;
            int last0=-1,last1=-1;
            for(int j=1;j<=n;j++)
            {
                if(((i>>(j-1))&1))
                {
                    if(last1==a[j])
                    {
                        cnt+=last1;
                    }
                    else last1=a[j];
                }
                else
                {
                    if(last0==a[j])
                    {
                        cnt+=last0;
                    }
                    else last0=a[j];
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<'\n';
    }
    return 0;
}