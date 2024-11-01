#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,num[MAXN],a[MAXN],lst,tree[MAXN];
int nu[MAXN],sz;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]++;
	}
	int ans=n;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1])nu[++sz]=a[i];
	}
	int could_kill=num[nu[1]];
	for(int i=2;i<=sz;i++){
		ans-=min(could_kill,num[nu[i]]);
		could_kill=max(could_kill-num[nu[i]],0);
		could_kill+=num[nu[i]];
	}
	cout<<ans;
	return 0;
}
