#include<bits/stdc++.h>
using namespace std;
int a[20],arr[20],brr[20];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--)
    {
        int maxn=-1;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<=(1<<n)-1;i++)
        {
            for(int j=1;j<=n;j++)
            {
                arr[j]=arr[j-1];
                brr[j]=brr[j-1];
                if(!(i&(1<<(n-j)))) arr[j]=j;
                else brr[j]=j;
            }
            int ans=0;
            for(int j=1;j<=n;j++)
            {
                if(!(i&(1<<(n-j))))
                {
                    if(a[arr[j-1]]==a[j]){ans+=a[j];}
                }
                else
                {
                    if(a[brr[j-1]]==a[j]){ans+=a[j];}
                }
            }
            maxn=max(maxn,ans);
        }
        cout<<maxn<<endl;
    }
    return 0;
}
