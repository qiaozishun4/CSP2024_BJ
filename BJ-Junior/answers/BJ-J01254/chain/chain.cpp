#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
vector<int> mp[1001];
bool t[200001];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T,n,k,q,l,tmp,r,c,lst=0;
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++) mp[i].clear();
        memset(t,0,sizeof(t));
        for(int i=1;i<=n;i++)
        {
            cin>>l;
            for(int j=1;j<=l;j++)
            {
                cin>>tmp;
                mp[i].push_back(tmp);
                if(tmp==1) lst=j;
                if((j!=1 && j-lst+1<=k)) t[tmp]=1;
            }
        }
        while(q--)
        {
            cin>>r>>c;
            if(t[c]==1) cout<<"1\n";
            else cout<<"0\n";
        }
    }
    cout<<flush;
    return 0;
}
