#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long n,t,a[100010]={-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108};
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int i=15;i<=n;i++)
        {
            a[i]=(a[i-7]*pow(10,floor((i-1)/7)-1))+8;
        }
        cout<<a[n-1]<<endl;
    }
    return 0;
}
