#include <iostream>
#include <cstring>

using namespace std;

int n,k,q;
string s[10005];

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
        }
        for(int i=0;i<q;i++)
        {
            int r,c;
            cin>>r>>c;
            bool yes=false;
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<s[i].length();j++)
                {
                    if(s[i][j]==c)
                    {
                        yes=true;
                    }
                }
            }
            if(!yes)
            {
                cout<<0<<endl;
                continue;
            }
            cout<<1<<endl;
        }
    }
    return 0;
}
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
