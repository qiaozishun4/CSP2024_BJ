#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int n;
        long long a[200005],c[200005],ans;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        if(n==1)
        {
            cout<<0;
        }
        if(n==2)
        {
            if(a[1]==a[2])
            {
                cout<<a[1];
            }
            else
            {

                cout<<0;
            }
        }
    }
}
