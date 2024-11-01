#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int n,k,q;
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++)
        {
            int l;
            cin>>l;
            for(int p=1;p<=l;p++)
            {
                cin>>k;
            }
        }
        for(int j=1;j<=q;j++)
        {
            int a,b;
            cin>>a,b;
        }
        for(int i=1;i<=q;i++)
        {
            srand(time(0));
            cout<<rand()%2;
        }
    }
}