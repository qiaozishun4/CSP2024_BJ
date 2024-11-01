#include<bits/stdc++.h>
using namespace std;
long long n,a[114513];
set<long long> s;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    long long i,j,k;
    long long T;
    cin>>T;
    while(T--)
    {
        long long cnt=0,ans=0;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            s.insert(a[i]);
            ans+=a[i];
        }
        for(auto i:s)
           cnt+=i;
        cout<<ans-cnt<<endl;
    }
    return 0;
}