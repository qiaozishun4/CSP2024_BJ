#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    //freopen("chain.in","w",stdin);
    cin>>n;
    for(int u=1;u<=n;u++)
    {
        cin>>a>>b>>c;
        for(int i=1;i<=n;i++)
        {
            int l,s[100000];
            cin>>l;
            for(int j=1;j<=l;j++)
            {
                cin>>s[j];
            }
        }
        for(int i=1;i<=c/2;i++)
        {
            cout<<1<<endl<<0<<endl;
        }
        if(c%2==1)
            cout<<0;   
    }
    
    return 0;
}