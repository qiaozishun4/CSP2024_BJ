#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,l,s[200005],r,c;
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
            cin>>l;
            for(int j=1;j<=l;j++)
            {
                cin>>s[i];
            }
        }
        for(int i=1;i<=q;i++)
        {
            flag=false;
            cin>>r>>c;
            for(int i=1;i<=n;i++)
            {
                if(s[i]==1)
                {
                    pos1=i
                }
                if(s[i]==c)
                {
                    flag=1;
                    pos=i;
                    break;
                }
            }
            if(!flag)
            {
                cout<<0<<endl;
                continue;
            }
            if((pos-pos1)*1.0/r>k*1.0)
            {
                cout<<0<<endl;
                continue;
            }
            if(pos-pos1<r)
            {
                cout<<0<<endl;
                continue;
            }
            cout<<1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}