#include<bits/stdc++.h>
using namespace std;
int s[1010][2010],l[1010],near1[1010][2010];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,q;
        cin>>n>>k>>q;
        memset(near1,-0x3f,sizeof near1);
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];j++)
            {
                cin>>s[i][j];
                if(s[i][j]==1)near1[i][j]=1;
                else near1[i][j]=near1[i][j-1]+1;
            }
        }
        while(q--)
        {
            int r,c;
            cin>>r>>c;
            if(r==1)
            {
                bool flag=0;
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=l[i];j++)
                    {
                        if(s[i][j]==c&&near1[i][j]>=2&&near1[i][j]<=k)
                        {

                            flag=1;
                        }
                    }
                cout<<flag<<endl;
            }
        }
    }
    return 0;
}