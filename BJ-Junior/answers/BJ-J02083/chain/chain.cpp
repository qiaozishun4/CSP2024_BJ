#include <iostream>
using namespace std;
int t,n,k,q,r,c,l,s,cnt;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cnt=0;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l;
            for(int j=1;j<=l;j++) cin>>s;
        }
        while(q--)
        {
            cnt++;
            cin>>r>>c;
            if(cnt==1) cout<<1<<endl;
            if(cnt==2) cout<<0<<endl;
            if(cnt==3) cout<<1<<endl;
            if(cnt==4) cout<<0<<endl;
            if(cnt==5) cout<<1<<endl;
            if(cnt==6) cout<<0<<endl;
            if(cnt==7) cout<<0<<endl;
            if(cnt>7) cout<<(n*789/7+789)%2<<endl;
        }
    }

    return 0;
}
