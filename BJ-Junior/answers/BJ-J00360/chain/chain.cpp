#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5;
int s[MAX][MAX],r,c,fl=0,n,k;
void f(int id,int nex)
{
    if(r==0)
    {
        if(nex==c) fl=1;
        return;
    }
    else for(int i=1;i<=n&&fl==0;i++)
    {
        if(i!=id)
        {
            for(int j=1;j<=s[i][0]&&fl==0;j++)
            {
                if(s[i][j]==nex)
                {
                    for(int l=j+1;l<=j+k&&l<=s[i][0]&&fl==0;l++)
                    {
                        r--;
                        f(i,s[i][l]);
                        r++;
                    }
                }
            }
        }
    }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i][0];
            for(int j=1;j<=s[i][0];j++) cin>>s[i][j];
        }
        while(q--)
        {
            fl=0;
            cin>>r>>c;
            f(0,1);
            cout<<fl<<endl;
        }
    }
    return 0;
}
