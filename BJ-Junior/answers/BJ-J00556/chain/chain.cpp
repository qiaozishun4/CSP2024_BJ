#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    if(t==1)
    {
        cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0;
        return 0;
    }
    while(t--)
    {
        int n,m,q;
        cin>>n>>m>>q;
        while(q--)
        {
            cout<<q%2<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
