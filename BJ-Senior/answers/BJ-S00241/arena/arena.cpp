#include<bits/stdc++.h>
using namespace std;
int t,n,b;
int a[200005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
            b=0;
            for(int k=j-1;k>=1;k--)
            {
                if(a[k]==a[j])
                {
                    b=1;
                }
            }
        }
        cout<<b;
        return 0;
    }
}
