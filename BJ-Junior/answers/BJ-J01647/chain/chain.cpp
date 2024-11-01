#include<iostream>
#include<cstdio>
using namespace std;

int main()
{   freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,k,q;
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++)
        {
            int l;
            cin>>l;
            for(int m=1;m<=l;m++)
            {

                int a;
                cin>>a;
            }
        }
        for(int j=1;j<=q;j++)
        {
            int x,y;
            cin>>x>>y;
            cout<<(y-x)%2<<endl;
        }
    }
    return 0;
}