#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N=1e5+10;
map<int,int> box;
int n;
signed main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        box[x]++;
    }
    int ans=n;
    int a1,b1,a2,b2;
    bool f=false;
    for(auto x:box)
    {
        if(!f)
        {
            a1=x.first;
            b1=x.second;
            f=true;
        }
        else
        {
            a2=x.first;
            b2=x.second;
            ans-=min(b1,b2);
            if(min(b1,b2)==b2) continue;
            a1=a2,b1=b2;
        }
    }
    cout<<ans<<endl;
    return 0;
}
