#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool v[N];
int vis[N];
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
        //cout<<n<<k<<q;
        for(int i=0;i<N;i++)
        {
            vis[i]=0;
            v[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            int l;
            cin>>l;

            deque<int> dq;

            for(int j=1;j<=l;j++)
            {
                int x;
                cin>>x;
                vis[x]++;
                if(dq.size()<k)
                {

                    dq.push_front(x);
                    if(vis[1]>0) v[x]=1;
                }
                else
                {
                    dq.push_front(x);
                    vis[dq.back()]--;
                    dq.pop_back();
                    if(vis[1]>0) v[x]=1;
                }

            }

            while(!dq.empty())
            {
                vis[dq.back()]--;
                dq.pop_back();
            }
        }
        while(q--)
        {
            int r,c;
            cin>>r>>c;
            //cout<<r<<c;
            cout<<v[c]<<endl;
        }
    }

    return 0;
}
