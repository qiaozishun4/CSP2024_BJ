#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t[N],maxx,ans,l;
vector<int> c;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int r;
		scanf("%d",&r);
		t[r]++;
		maxx=max(maxx,r);
	}
	for(int i=1;i<=maxx;i++){
		if(t[i]==0) continue;
		c.push_back(t[i]);
	}
	l=c.size();
	ans=c[0];
	for(int i=1;i<l;i++) ans=c[i]+max(0,ans-c[i]);
	printf("%d\n",ans);
	return 0;
}
