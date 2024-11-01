#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int main()
{
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        while(n>0)
        {
            cout<<8;
            n-=7;
        }
        cout<<endl;
    }
    return 0;
}
