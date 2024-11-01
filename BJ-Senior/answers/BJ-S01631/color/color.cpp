#include <bits/stdc++.h>
using namespace std;
int a[200005],c[1000005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        long long sum=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            c[a[i]]++;
        }
        for(int i=1;i<=1000005;i++)
        {
            if(c[i]>=2)
            {
                sum+=c[i]*(c[i]-1);
            }
        }
        cout<<sum<<endl;
    }
}
