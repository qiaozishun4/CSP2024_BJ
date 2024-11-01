#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200001],b[200001],d;
long long k()
{
    int y=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(b[i]==b[j])
            {
                if(a[i]==a[j]) y+=a[j];
                break;
            }
        }
    }
    return y;
}
int s(int i)
{
    if(i>n)
    {
        d=max(d,k());
        return 0;
    }
    b[i]=0;
    s(i+1);
    b[i]=1;
    s(i+1);
    return 0;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        d=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        s(1);
        cout<<d<<endl;
    }
    return 0;
}