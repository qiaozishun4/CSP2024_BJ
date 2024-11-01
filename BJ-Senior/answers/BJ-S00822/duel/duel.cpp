#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
int n;
ll a[N+5];
priority_queue<ll> qa;
priority_queue<ll> qb;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	ll res=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qa.push(a[i]);
		qb.push(a[i]);
	}
	while(!qb.empty()){
		if(qa.top()>qb.top()){
			res--;
			qa.pop();
		}
		qb.pop();
	}
	cout<<res<<"\n";
	return 0;
}
//caijiuduolian