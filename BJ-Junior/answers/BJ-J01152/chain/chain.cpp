#include<bits/stdc++.h>
using namespace std;
int l[100002],s[1002][2002];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T)
    {
        T--;
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];j++)
                cin>>s[i][j];
        }
        for(int i=1;i<=q;i++)
        {
            int r,c;
            cin>>r>>c;
            bool flag=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=l[i];j++)
                {
                    if(s[i][j]==c&&j>1&&j<=k)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    break;
            }
            if(flag==1)
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
    }
    return 0;
}