#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,q;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>q>>q>>q;
        for(int j=1;j<=q;j++)
        {
            if(j%2==1)
            {
                cout<<"1\n";
            }
            else
            {
                cout<<"0\n";
            }
        }
    }
}
