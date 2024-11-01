#include<bits/stdc++.h>
using namespace std;
#define int long long
const int NR=2e5+10;
const int MR=1e6+10;
int n,a[NR],len,v[NR],f[NR],g[NR],pre[NR],buc[MR];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	int res=0;len=0;
	for(int i=1;i<=n;i++)
		if(a[i]==a[i-1])res+=a[i];
		else v[++len]=a[i];
	n=len;
	for(int i=1;i<=n;i++)a[i]=v[i];
	memset(pre,0,sizeof(pre));
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	memset(buc,0,sizeof(buc));
	int maxf=0;
	for(int i=1;i<=n;i++){
		int x=buc[a[i]];
		if(x)f[i]=a[i]+g[x];
		maxf=max(maxf,f[i]);
		g[i]=maxf;buc[a[i]]=i;
		if(i>1){
			g[i-1]=max(g[i-1],f[i]);
			pre[i-1]=max(pre[i-2],g[i-1]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	cout<<ans+res<<endl;
}

signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}