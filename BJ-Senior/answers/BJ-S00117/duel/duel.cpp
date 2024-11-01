#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,a[N];
priority_queue<ll,vector<ll>,greater<ll> >q1,q2;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i],q2.push(a[i]);
	while(!q2.empty()){
		ll u=q2.top();q2.pop();
		if(!q1.empty()&&q1.top()<u){q1.pop();}
		q1.push(u);
	}
	cout<<q1.size();
	return 0;
}
