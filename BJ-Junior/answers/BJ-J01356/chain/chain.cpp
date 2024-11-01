#include <bits/stdc++.h>

using namespace std;

int t,n,k,q,l,m;
bool s[200005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l;
            for(int j=1;j<=l;j++){cin>>m;s[j]=1;}
        }
        int r,c,last=1;
        for(int i=1;i<=q;i++)
        {
            cin>>r>>c;
            int tmp=c;
            while(c>=10)c/=10;
            if(last==c||s[c]!=1||last%10>2||last%10!=c)cout<<0<<endl;
            else cout<<1<<endl;
            last=tmp;
        }
    }
    return 0;
}
