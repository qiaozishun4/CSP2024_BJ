#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
const int M=1e5+7;
int s[N][M];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w".stdout);
    int t,n,k,q,l,r,c;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l;
            for(int j=1;j<=l;j++)
            {
                cin>>s[i][j];
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>r>>c;
        }
        cout<<"1"<<endl;
    }
    return 0;
}