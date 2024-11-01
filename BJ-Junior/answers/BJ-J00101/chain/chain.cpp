#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,q,l[200005],s[2005][2005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];j++) cin>>s[i][j];
        }
        while(q--)
        {
            int r,c,flag=0;
            cin>>r>>c;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=l[i];j++)
                {
                    if(s[i][j]==c)
                    {
                        //cout<<j<<" "<<k<<endl;
                        for(int w=j;w>=j-k+1;w--)
                        {
                            //cout<<j<<" ";
                            if(s[i][w]==1)
                            {
                                flag=1;
                                break;
                            }
                        }
                    }
                    if(flag==1) break;
                }
                if(flag==1) break;
            }
            if(flag==1) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}
