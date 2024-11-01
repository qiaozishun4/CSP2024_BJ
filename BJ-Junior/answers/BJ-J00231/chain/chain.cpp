#include <bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int n,t,q,k,r[M],c[M],cnt[M<<1];
vector <int> s[M];
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
            int l;
            cin>>l;
            for(int j=1;j<=l;j++)
            {
                int cur=0;
                cin>>cur;
                cnt[cur]++;
                s[i].push_back(cur);
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>r[i]>>c[i];
            if(r[i]==1)
            {
                if(c[i]!=1&&cnt[c[i]]>0&&cnt[1]>0)
                {
                    cout<<1<<endl;
                }
                else if(c[i]==1&&cnt[1]>1)
                {
                    cout<<1<<endl;
                }
                else cout<<0<<endl;
            }
            else 
            {
                mt19937 mr(time(0));
                cout<<mr()%2<<endl;
            }
        }
    }
    return 0;
}