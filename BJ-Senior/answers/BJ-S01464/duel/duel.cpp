#include <bits/stdc++.h>
using namespace std;
int n, a, cnt[100002], mx, s;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a;
		cnt[a]++;
		mx=max(mx, a);
	}
	for(int i = 1; i <= 100000; i++){
		if(cnt[i]){
			q.push({i, cnt[i]});
		}
	}
	while(1){
		pair<int, int> a=q.top(), b;
		q.pop();
		b=q.top();	
		if(b.second>a.second){
			s=max(s-(b.second-a.second), 0);
		}
		else{
			s+=a.second-b.second;
		}
		if(b.first==mx){
			s+=b.second;
			break;
		}
	}
	cout<<s;
	return 0;
}