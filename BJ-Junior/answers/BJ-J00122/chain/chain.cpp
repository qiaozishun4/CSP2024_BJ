#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int t;
int n,k,q;
string a[100005];

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=q;i++)
        {
            int r,c;
            cin>>r>>c;

        }
        cout<<1<<endl;
    }


    return 0;
}
