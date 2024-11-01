#include<bits/stdc++.h>
using namespace std;
int n,a[100005],mp[100005];
bool panduan(int md){
	int m=n-md,wz=1,cnt=0,tot=1;
	//cout<<md<<"\n";
	memset(mp,0,sizeof(mp));
	for(int i=2;i<=m;++i){
		if(a[wz]<a[i]) mp[wz]=1,wz++,cnt++;
	}
	for(int i=1;i<=m;++i){
		if(!mp[i]){
			//cout<<i<<"\n";
			while(a[i]>=a[m+tot]&&m+tot<n) tot++;
			if(a[i]>=a[m+tot]) return 0;
			tot++;
			cnt++;
		}
	}
	if(cnt<m) return 0;
	return 1;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;++i) cout<<a[i]<<" ";cout<<"\n";
	int l=1,r=n,anslr,mid;
	while(l<=r){
		mid=l+r>>1;
		if(panduan(mid)) r=mid-1,anslr=mid;
		else l=mid+1;
	}
	cout<<anslr<<"\n";
	return 0;
}