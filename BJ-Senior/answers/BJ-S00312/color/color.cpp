#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int T,n,a[N],lst[N];
ll f[N],g[N],s[N];
map<int,int> mp;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n,mp.clear();
		for(int i=1;i<=n;i++)	cin>>a[i];
		for(int i=1;i<=n;i++)	lst[i]=mp[a[i]],mp[a[i]]=i;
		for(int i=1;i<=n;i++){
			f[i]=g[i]=max(f[i-1],g[i-1]),s[i]=s[i-1];
			if(a[i]==a[i-1])	f[i]+=a[i],s[i]+=a[i];
			else if(lst[i])	g[i]=max(g[i],g[lst[i]+1]+s[i]-s[lst[i]+1]+a[i]);
		}
		cout<<max(f[n],g[n])<<'\n';
	}
	return 0;
}