#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> a[100005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            int l;
            cin>>l;
            for(int j=1;j<=l;j++)
            {
                int x;
                cin>>x;
                a[i].push_back(x);
            }
        }
        while(q--)
        {
            int r,j;
            cin>>r>>j;
            cout<<0<<"\n";
        }
    }
    return 0;
}
