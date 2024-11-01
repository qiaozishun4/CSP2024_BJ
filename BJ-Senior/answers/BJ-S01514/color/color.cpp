#include <bits/stdc++.h>
using namespace std;
int n,sum;
long long a[10000005],c[10000005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>c[i];
        for (int j=1;j<=c[i];j++)
        {
            cin>>a[j];
        }
        sort(1,c[i],a);
        for(int i=1;i<=n;i++)
        {
            if (a[i]==a[i+1])
            {
                sum+=a[i];
            }
        }
        cout <<sum<<endl;
        sum=0;
    }
    return 0;
}