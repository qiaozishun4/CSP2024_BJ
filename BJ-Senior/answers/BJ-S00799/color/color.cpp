#include<bits/stdc++.h>
using namespace std;
int sum,c[1000005],a[1000055],t,n;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    cin>>t;
    for(int o=1;o<=t;o++)
    {
        sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            c[i]=0;

        }
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]==a[i])
                {
                    sum=sum+a[i];
                }
            }

        }
        cout<<sum<<endl;
    }

    return 0;
}