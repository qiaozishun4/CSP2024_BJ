#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t;
int n,k,q;
int l[N],c[N],r[N];
int cnt[N];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)
        {
            bool flag=false;
            int t3=0;
            cin>>l[i];
            for(int j=1;j<=l[i];j++)
            {
                int t2;
                cin>>t2;
                if(t2==1&&!flag)
                    flag=true,t3=j;
                if(flag&&!cnt[t2])
                    cnt[t2]=j-t3+1;
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>r[i]>>c[i];
            if(r[i]==1)
            {
                cout<<(cnt[c[i]]<=k)<<endl;
            }
            else
                cout<<1<<endl;
        }
    }
    return 0;
}
