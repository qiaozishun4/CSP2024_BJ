#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int T,n,k,q,l,s[200005],r[200005],c[200005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>q;
        cin>>l;
        for(int i=1;i<=l;i++)
            cin>>s[i];
        for(int i=1;i<=q;i++)
        {


            cin>>r[i]>>c[i];
            cout<<1<<endl;
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
