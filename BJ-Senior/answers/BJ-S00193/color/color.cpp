#include <bits/stdc++.h>
using namespace std;
int t;
int a[200005];
int c[200005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        long long s=0;
        for(int i=2;i<=n;i++)
        {
            int t1=0;
            int t2=0;
            for(int j=i-1;j>=1;j--)
            {
                if(a[j]==a[i])
                {
                    if(t1*t2==0)
                      s+=a[j];
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
