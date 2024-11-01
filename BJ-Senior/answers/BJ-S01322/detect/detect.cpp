#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int n,m,V,S,ans=0,mx=INT_MIN;
	int s[10010],v[10010],a[10010],c[10010],r;
	cin>>n>>m>>S>>V;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>v[i]>>a[i];
	}
	for(int i=1;i<=m;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		if(v[i]<=V) continue;
		r=upper_bound(c+1,c+1+m,s[i])-c-1;
		if(r==-1) continue;
		ans++;
		mx=max(mx,r);
	}cout<<ans<<" "<<mx;
	return 0;
}

