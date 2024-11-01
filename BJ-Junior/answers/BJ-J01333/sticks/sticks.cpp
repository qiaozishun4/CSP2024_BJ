#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int b[]={6,2,5,5,4,5,6,3,7,6};
int a[1000],t,n,k;
int ccount(int x)
{
    int ret=0;
    while(x)
    {
        ret+=b[x%10];
        x/=10;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    memset(a,-1,sizeof(a));
    for(int i=0;i<=100000;i++)
    {
        int x=ccount(i);
        if(a[x]==-1)
        {
            a[x]=i;
        }
    }
    a[0]=-1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=28)
        {
            cout<<a[n]<<"\n";
            continue;
        }
        cout<<a[(n%7)+21];
        k=(n/7)-3;
        while(k--)
        {
            cout<<8;
        }
        cout<<"\n";
    }
    return 0;
}
