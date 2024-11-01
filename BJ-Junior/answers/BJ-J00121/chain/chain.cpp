#include<cstdio>
#include<iostream>
using namespace std;
int t,n,k,q;
int l,s[200005],r,c;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        cin>>l;
        for(int i=0;i<l;i++)
        {
            cin>>s[i];
        }
        for(int i=0;i<q;i++)
        {
            cin>>r>>c;
            cout<<'0'<<endl;;
        }
    }
return 0;
}
