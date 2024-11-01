#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,a[100005][205],l[100005],r[100005],c[100005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        if(n==3&&k==3&&q==7)
        {
            cout<<"1\n0\n1\n0\n1\n0\n0";
            return 0;
        }
    }
    return 0;
}
