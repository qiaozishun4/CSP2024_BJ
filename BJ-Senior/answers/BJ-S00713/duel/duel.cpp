#include<bits/stdc++.h>
using namespace std;
int n,a[102337];
queue<int> q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	q.push(a[1]);
	for(int i=2;i<=n;i++){
		q.push(a[i]);
		if(a[i]>q.front())q.pop();
	}
	int ans=0;
	while(!q.empty()){
		ans++;
		q.pop();
	}
	cout << ans;
	return 0;
}