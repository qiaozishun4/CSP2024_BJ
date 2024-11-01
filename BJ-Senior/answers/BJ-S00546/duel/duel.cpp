#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
queue<ll> q;
ll n,r[100005],ans;
int main()
{
	ios::sync_with_stdio(false);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;ans=n;
	for(ll i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+n+1);
	q.push(r[1]);
	for(ll i=2;i<=n;i++)
    {
        if(r[i]>q.front())
        {
            q.pop();
            ans--;
        }
        q.push(r[i]);
    }
    cout<<ans;
	return 0;
}
