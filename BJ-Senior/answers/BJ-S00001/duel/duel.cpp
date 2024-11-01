#include<bits/stdc++.h>
using namespace std;
const int N=100005;
multiset<int>s;
multiset<int>tp;
int n;
int a[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
        tp.insert(a[i]);
    }
    int ans=0;
    while(!s.empty())
    {
        int u=(*s.begin());
        s.erase(s.begin());
        multiset<int>::iterator tmp=(tp.upper_bound(u));
        if(tmp==tp.end())
        {
            s.insert(u);
            break;
        }
        tp.erase(tmp);
    
    }
    cout<<ans+(int)(s.size())<<'\n';
}
