#include<bits/stdc++.h>
using namespace std;
int r[100005];
priority_queue<int> q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&r[i]);
	sort(r+1,r+1+n);
	for(int i=1;i<=n;i++) q.push(-r[i]);
	for(int i=1;i<=n;i++) if(r[i]>(-q.top())){
		q.pop();
	}
	cout<<q.size();
	return 0;
}